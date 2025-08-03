// MIT License

// Copyright (c) 2025 kcExperts, Inc. All Rights Reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "defines.h"
#include "cli.h"
#include <iostream>
#include <iomanip>

namespace dsp
{

namespace items
{
    extern item_lookup_t item_lookup;
} //namespace items

namespace cli
{

CLI::CLI(int argc, char** argv)
{
    parser = new ::parser::Parser(argc, argv);

    flags.emplace("help", flag_arg{
        'h',
        std::nullopt,
        "Show this help message and exit"
    });

    flags.emplace("list", flag_arg{
        'l',
        std::optional<std::vector<std::string>>{{"items", "structs"}},
        "List available items or structures (structs unimplemented)"
    });

    flags.emplace("craft", flag_arg{
        'c',
        std::optional<std::vector<std::string>>{{"<item>"}},
        "Display the ressources needed for the item (use in tandem with other flags)"
    });

    flags.emplace("depth", flag_arg{
        'd',
        std::optional<std::vector<std::string>>{{"<level>"}},
        "Limit the crafting tree recursion depth (0 = unlimited)"
    });

    flags.emplace("belt", flag_arg{
        'b',
        std::optional<std::vector<std::string>>{{"<tier>"}},
        "Display quantities as belt throughput (tier 1, 2, or 3)"
    });

    flags.emplace("minute", flag_arg{
        'm',
        std::optional<std::vector<std::string>>{{"<amount>"}},
        "Target production rate per minute (e.g., 60)"
    });

    flags.emplace("time", flag_arg{
        't',
        std::nullopt,
        "Show individual crafting times for each item"
    });

    flags.emplace("propagate", flag_arg{
        'p',
        std::nullopt,
        "Enable propagation of production values through tree (only for --tree)"
    });

        flags.emplace("tree", flag_arg{
        std::nullopt,
        std::optional<std::vector<std::string>>{{"<item>"}},
        "Shows full crafting tree (this can get quite big)"
    });
};

CLI::~CLI() {
    delete parser;
}

void CLI::format_option(const std::map<std::string, flag_arg>::const_iterator& it)
{
    std::string flags_str = "--" + it->first;

    if (it->second.s_flag.has_value()) {
        flags_str += " -" + std::string(1, it->second.s_flag.value());
    }

    std::string opt_str;
    if (it->second.opt.has_value() && !it->second.opt->empty()) {
        // Join vector<string> elements with '|'
        std::ostringstream oss;
        oss << "[";
        const auto& opts = *it->second.opt;
        for (size_t i = 0; i < opts.size(); ++i) {
            oss << opts[i];
            if (i != opts.size() - 1)
                oss << "|";
        }
        oss << "]";
        opt_str = oss.str();
    }

    std::cout << "    "
              << std::left << std::setw(20) << flags_str
              << std::left << std::setw(28) << opt_str
              << it->second.desc << "\n";
}

void CLI::add_arg(std::string l_flag, std::optional<char> s_flag,
                  std::optional<std::vector<std::string>> opt, std::string desc)
{
    auto [it, inserted] = flags.emplace(l_flag, flag_arg{s_flag, opt, desc});
    if (!inserted) {
        throw std::runtime_error("Flag '--" + l_flag + "' already exists");
    }
}

void CLI::print_help()
{
    std::cout << "Options:\n";
    auto help_it = flags.find("help");
    if (help_it != flags.end()) {
        format_option(help_it);
    }

    for (auto it = flags.begin(); it != flags.end(); ++it) {
        if (it->first == "help") continue;
        format_option(it);
    }
}

void CLI::print_items()
{
    const int items_per_row = 3;
    const int col_width = 35; // adjust for nice spacing
    std::cout << "\n" << std::left << "Listing all items..." << "\n" << "\n";
    int count = 0;
    for (const auto& [name, item_ptr] : dsp::items::item_lookup)
    {
        std::cout << std::left << std::setw(col_width) << name;
        count++;

        if (count % items_per_row == 0)
            std::cout << "\n";
    }

    std::cout << "\n";
}

void CLI::print_craft_base_recursive(
    const item_t* item,
    int indent,
    std::unordered_set<const item_t*>* visited,
    unsigned int current_depth,
    unsigned int multiplier)
{
    if (!item || item->is_harvestable)
        return;

    if (!visited) visited = new std::unordered_set<const item_t*>();

    if (visited->count(item)) {
        std::cout << std::string(indent, ' ') << "(already processed)\n";
        return;
    }
    visited->insert(item);

    const auto& recipes = item->recipes;
    auto it = recipes.find(recipe_identifier_e::MAIN);
    if (it == recipes.end()) {
        std::cout << std::string(indent, ' ') << "No MAIN recipe available.\n";
        return;
    }

    const recipe_t& recipe = it->second;

    if (display_time_f) {
        double displayed_craft_time = use_mul_f ? recipe.craft_time.get_time() * multiplier : recipe.craft_time.get_time();
        std::cout << std::string(indent, ' ') << "- Craft time: "
                  << std::fixed << std::setprecision(2) << displayed_craft_time << "s\n";
    }

    if (depth == 1) {
        std::cout << std::string(indent, ' ') << "- Amount produced: " << recipe.produced << "\n";
    }

    std::cout << std::string(indent, ' ') << "- Ingredients:\n";

    for (const auto& [sub_item, amount] : recipe.items) {
        std::string name = "(unknown)";
        for (const auto& [key, val] : items::item_lookup) {
            if (val == sub_item) {
                name = key;
                break;
            }
        }

        unsigned int total_amount = use_mul_f ? amount * multiplier : amount;

        std::cout << std::string(indent + 4, ' ') << total_amount << "x " << name;

        if (sub_item->is_harvestable) {
            std::cout << " (harvestable)\n";
        } else {
            std::cout << "\n";
            if (depth == 0 || current_depth + 1 < depth) {
                print_craft_base_recursive(sub_item, indent + 8, visited, current_depth + 1, use_mul_f ? total_amount : 1);
            }
        }
    }

    if (indent == 0)
        delete visited;
}

void CLI::print_craft_base(std::string item)
{
    auto it = items::item_lookup.find(item);
    if (it == items::item_lookup.end()) {
        std::cout << "Invalid item: '" << item << "'\n";
        return;
    }

    const item_t* item_ptr = it->second;
    std::cout << "Craft info for: " << item << "\n";

    if (item_ptr->is_harvestable) {
        std::cout << "  This item is harvestable — no crafting needed.\n";
        return;
    }

    print_craft_base_recursive(item_ptr, 2, nullptr, 0, 1);
}

void CLI::accumulate_raw_materials(
    const item_t* item,
    double multiplier,
    std::unordered_map<const item_t*, double>& raw_materials,
    unsigned int depth,
    unsigned int& max_depth_reached,
    unsigned int current_depth)
{
    if (!item)
        return;

    // Track max depth reached
    if (current_depth > max_depth_reached)
        max_depth_reached = current_depth;

    if (item->is_harvestable) {
        raw_materials[item] += multiplier;
        return;
    }

    // If depth > 0 and current_depth reached depth, accumulate as raw and stop recursing
    if (depth > 0 && current_depth >= depth) {
        raw_materials[item] += multiplier;
        return;
    }

    auto it = item->recipes.find(recipe_identifier_e::MAIN);
    if (it == item->recipes.end()) {
        raw_materials[item] += multiplier;
        return;
    }

    const recipe_t& recipe = it->second;

    for (const auto& [sub_item, amount] : recipe.items) {
        accumulate_raw_materials(sub_item, multiplier * amount, raw_materials, depth, max_depth_reached, current_depth + 1);
    }
}

void CLI::print_raw_materials(
    const std::unordered_map<const item_t*, unsigned int>& raw_materials)
{
    // Print the raw materials nicely
    for (const auto& [item_ptr, amount] : raw_materials) {
        // Find item name from item_lookup
        std::string name = "(unknown)";
        for (const auto& [key, val] : items::item_lookup) {
            if (val == item_ptr) {
                name = key;
                break;
            }
        }
        std::cout << "    " << amount << "x " << name << " (harvestable)\n";
    }
}

void CLI::print_organized(const std::string& item_name)
{
    auto it = items::item_lookup.find(item_name);
    if (it == items::item_lookup.end()) {
        std::cout << "Invalid item: '" << item_name << "'\n";
        return;
    }

    int belt_speed = 0;
    std::string belt_label;

    if (use_per_min_f && belt_f != NONE) {
        switch (belt_f) {
            case MK1:
                belt_speed = belt_mk1;
                belt_label = "MK1";
                break;
            case MK2:
                belt_speed = belt_mk2;
                belt_label = "MK2";
                break;
            case MK3:
                belt_speed = belt_mk3;
                belt_label = "MK3";
                break;
            default:
                break;
        }
    }

    const item_t* item = it->second;

    std::cout << "Craft info for: " << item_name << "\n";

    double crafts_needed = 1.0;

    auto rit = item->recipes.find(recipe_identifier_e::MAIN);
    if (rit != item->recipes.end()) {
        const auto& recipe = rit->second;

        if (use_per_min_f && recipe.produced > 0 && recipe.craft_time.get_time() > 0.0) {
            // Compute how many crafts per minute we need
            crafts_needed = per_min / static_cast<double>(recipe.produced);

            std::cout << "  - Target: " << per_min << " per minute\n";
            if (display_time_f) {
                std::cout << "  - Craft time: " << std::fixed << std::setprecision(2)
                          << recipe.craft_time.get_time() << "s\n";
            }
        } else if (display_time_f) {
            std::cout << "  - Craft time: " << std::fixed << std::setprecision(2)
                      << recipe.craft_time.get_time() << "s\n";
        }
    }

    if (use_per_min_f)
    {
        if (belt_speed > 0)
            std::cout << "  - Raw Materials/belt:\n";
        else
            std::cout << "  - Raw Materials/min:\n";
    } else
    {
        std::cout << "  - Raw Materials:\n";
    }

    std::unordered_map<const item_t*, double> raw_materials;
    unsigned int max_depth_reached = 0;

    // Call the depth-aware version with class member depth
    accumulate_raw_materials(item, crafts_needed, raw_materials, depth, max_depth_reached);

    if (depth > max_depth_reached) {
        std::cout << "[warning] Max recursion depth is " << max_depth_reached
                << " but depth was set to " << depth << "\n";
    }

    for (const auto& [mat, amt] : raw_materials) {
        std::string name = "(unknown)";
        for (const auto& [key, val] : items::item_lookup) {
            if (val == mat) {
                name = key;
                break;
            }
        }

        if (belt_speed > 0) {
            double fraction = amt / belt_speed;

            std::cout << "    " << std::fixed << std::setprecision(2)
                    << fraction << "x belt (" << belt_label << ") for "
                    << name;
        } else {
            std::cout << "    " << std::fixed << std::setprecision(2)
                    << amt << "x " << name;
        }

        if (mat->is_harvestable) {
            std::cout << " (harvestable)";
        }

        std::cout << "\n";
    }
}

void CLI::parse()
{
    // Check for help flag -h or --help
    if (parser->has_flag("-h") || parser->has_flag("--help")) {
        print_help();
        return; // Ignore everything else if help was requested
    }

    // Handle list flag -l or --list
    if (parser->has_flag("-l") || parser->has_flag("--list")) {
        // get positional arguments after -l or --list
        auto list_args = parser->get_positional_args("-l");
        if (list_args.empty())
            list_args = parser->get_positional_args("--list");

        if (!list_args.empty()) {
            const std::string& arg = list_args.front();
            if (arg == "items") {
                print_items();
                return;
            } else if (arg == "structs") {
                // Not implemented, do nothing or print info if you want
                std::cout << "Listing structs not implemented yet.\n";
                return;
            } else {
                std::cerr << "Error: Unknown argument for --list: '" << arg << "'\n";
                return;
            }
        } else {
            std::cerr << "Error: No argument provided for --list\n";
            return;
        }
    }

    // Scan for -d or --depth flag
    if (parser->has_flag("-d") || parser->has_flag("--depth")) {
        auto depth_args = parser->get_positional_args("-d");
        if (depth_args.empty())
            depth_args = parser->get_positional_args("--depth");

        if (!depth_args.empty()) {
            try {
                unsigned int d = std::stoul(depth_args.front());
                depth = d;  // Set class member depth
            } catch (const std::exception& e) {
                std::cerr << "Error: Invalid depth value '" << depth_args.front() << "'\n";
                return;
            }
        } else {
            std::cerr << "Error: No value provided for --depth\n";
            return;
        }
    }

    // Scan for -b or --belt flag
    if (parser->has_flag("-b") || parser->has_flag("--belt")) {
        auto belt_args = parser->get_positional_args("-b");
        if (belt_args.empty())
            belt_args = parser->get_positional_args("--belt");

        if (!belt_args.empty()) {
            try {
                int belt_val = std::stoi(belt_args.front());
                if (belt_val < 1 || belt_val > 3) {
                    std::cerr << "Error: Belt tier must be 1, 2, or 3\n";
                    return;
                }
                switch (belt_val) {
                    case 1: belt_f = MK1; break;
                    case 2: belt_f = MK2; break;
                    case 3: belt_f = MK3; break;
                    default: belt_f = NONE; break; // fallback
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: Invalid belt tier '" << belt_args.front() << "'\n";
                return;
            }
        } else {
            std::cerr << "Error: No value provided for --belt\n";
            return;
        }
    }

    // Scan for -m or --minute flag
    if (parser->has_flag("-m") || parser->has_flag("--minute")) {
        auto min_args = parser->get_positional_args("-m");
        if (min_args.empty())
            min_args = parser->get_positional_args("--minute");

        if (!min_args.empty()) {
            try {
                unsigned int m = std::stoul(min_args.front());
                use_per_min_f = true;
                per_min = m;
            } catch (const std::exception& e) {
                std::cerr << "Error: Invalid per-minute value '" << min_args.front() << "'\n";
                return;
            }
        } else {
            std::cerr << "Error: No value provided for --minute\n";
            return;
        }
    }

    // Scan for -t or --time flag
    if (parser->has_flag("-t") || parser->has_flag("--time")) {
        display_time_f = true;
    }

    // Scan for -p or --propagate flag
    if (parser->has_flag("-p") || parser->has_flag("--propagate")) {
        use_mul_f = true;
    }

    // Now check -c / --craft and -b / --base flags and their positional args
    std::string craft_arg;
    bool has_craft = false;
    if (parser->has_flag("-c") || parser->has_flag("--craft")) {
        auto c_args = parser->get_positional_args("-c");
        if (c_args.empty())
            c_args = parser->get_positional_args("--craft");

        if (!c_args.empty()) {
            craft_arg = c_args.front();
            has_craft = true;
        } else {
            std::cerr << "Error: No argument provided for --craft\n";
            return;
        }
    }

    std::string base_arg;
    bool has_base = false;
    if (parser->has_flag("--tree")) {
        auto tree_args = parser->get_positional_args("--tree");

        if (!tree_args.empty()) {
            base_arg = tree_args.front();
            has_base = true;
        } else {
            std::cerr << "Error: No argument provided for --tree\n";
            return;
        }
    }

    // If -c is found, ignore -b and call print_organized
    if (has_craft) {
        print_organized(craft_arg);
    }
    else if (has_base) {
        print_craft_base(base_arg);
    }
}

} // namespace cli
} // namespace dsp

