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