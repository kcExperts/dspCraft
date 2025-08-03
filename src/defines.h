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

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <initializer_list>
#include <limits>


// Common defines

namespace dsp
{

enum recipe_identifier_e
{
    MAIN,
    ADVANCED,
    // Hydrogen related since only hydrogen has > 2 recipes
    X_RAY_CRACKING,
    MASS_ENERGY_STORAGE
};

struct item_t;
struct time_storage_t;
struct recipe_t;

typedef std::unordered_map<recipe_identifier_e, recipe_t> recipe_container_t;
typedef std::vector<std::pair<const item_t*, unsigned int>> recipe_item_t;
// Only use 2 decimal precision (0.00)
typedef unsigned int amount_t;
typedef std::unordered_map<std::string, const item_t*> item_lookup_t;


struct item_t
{
    bool is_harvestable;
    bool df_farmable;
    unsigned short alt_rec;

	recipe_container_t recipes;
};

// Stores time with two decimal places. User should never access.
struct time_storage_t 
{
    unsigned int v = 0;

    time_storage_t(double x = 0.0)
        : v(x < 0.0 ? std::numeric_limits<unsigned int>::max() : static_cast<unsigned int>(x * 100.0))
    {}
    void set_time(double x)
    {
        v = static_cast<unsigned int>(x < 0.0 ? 0 : x * 100.0);
    }
    double get_time() const
    {
        return v / 100.0;
    }
};

struct recipe_t
{
    recipe_item_t items;
    time_storage_t craft_time;
    amount_t produced;
};

// Items contain the amount needed as well
inline recipe_t set_recipe(std::initializer_list<std::pair<const item_t*, amount_t>> items, double time, amount_t produced)
{
    recipe_item_t item_list(items);
    time_storage_t t(time);
    return {item_list, t, produced};
};


} // namepsace dsp