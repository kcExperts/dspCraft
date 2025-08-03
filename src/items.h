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

#include "defines.h"
#include <iostream>
#include <iomanip>

namespace dsp
{
namespace items
{

// Lookup table
item_lookup_t item_lookup;

// Initialize base descriptors

// Row 1
item_t iron_ore                       {true, false, 0};
item_t copper_ore                     {true, false, 0};
item_t stone                          {true, false, 0};
item_t coal                           {true, false, 0};
item_t silicon_ore                    {true, false, 1};
item_t titanium_ore                   {true, false, 0};
item_t water                          {true, false, 0};
item_t crude_oil                      {true, false, 0}; 
item_t hydrogen                       {true, true, 4}; //Exclude fractionation
item_t deuterium                      {true, true, 1}; //Exclude fractionation
item_t antimatter                     {false, true, 1}; 
item_t core_element                   {false, true, 0};
item_t critical_photon                {true, false, 0};
item_t kimberlite_ore                 {true, false, 0};

// Row 2
item_t iron_ingot                     {false, true, 1};
item_t copper_ingot                   {false, true, 1};
item_t stone_brick                    {false, true, 1};
item_t graphite                       {false, true, 2};
item_t silicon_ingot                  {false, true, 1};
item_t titanium_ingot                 {false, true, 1};
item_t sulfuric_acid                  {false, false, 1};
item_t refined_oil                    {false, false, 2};
item_t hydrogen_fuel_rod              {false, true, 1};
item_t deuterium_fuel_rod             {false, true, 1};
item_t antimatter_fuel_rod            {false, true, 1};
item_t strange_annihilation_fuel_rod  {false, false, 1};
item_t missile_set                    {false, false, 1};
item_t fractal_silicon                {true, false, 0};

// Row 3
item_t magnet                         {false, true, 1};
item_t magnetic_coil                  {false, true, 1};
item_t glass                          {false, true, 1};
item_t diamond                        {false, true, 2};
item_t crystal_silicon                {false, true, 2};
item_t titanium_alloy                 {false, true, 1};
item_t combustible_unit               {false, true, 1};
item_t plastic                        {false, true, 1};
item_t organic_crystal                {true, false, 2};
item_t graphene                       {true, true, 2};
item_t annihilation_constraint_sphere {false, true, 1};
item_t magnum_ammo_box                {false, false, 1};
item_t supersonic_missile_set         {false, false, 1};
item_t grating_crystal                {true, true, 0};

// Row 4
item_t steel                          {false, true, 1};
item_t circuit_board                  {false, true, 1};
item_t prism                          {false, true, 1};
item_t electric_motor                 {false, true, 1};
item_t microcrystalline_component     {false, true, 1};
item_t proliferator_mk1               {false, false, 1};
item_t explosive_unit                 {false, true, 1};
item_t strange_matter                 {false, true, 1};
item_t titanium_crystal               {false, true, 1};
item_t carbon_nanotubes               {false, true, 2};
item_t particle_broadband             {false, true, 1};
item_t titanium_ammo_box              {false, false, 1};
item_t gravity_missile_set            {false, false, 1};
item_t stalagmite_crystal             {true, false, 0};

// Row 5
item_t gear                           {false, true, 1};
item_t plasma_exciter                 {false, true, 1};
item_t photon_combiner                {false, true, 2};
item_t electromagnetic_turbine        {false, true, 1};
item_t processor                      {false, true, 1};
item_t proliferator_mk2               {false, false, 1};
item_t crystal_explosive_unit         {false, true, 1};
item_t casimir_crystal                {false, true, 2};
item_t titanium_glass                 {false, true, 1};
item_t plane_filter                   {false, true, 1};
item_t quantum_chip                   {false, true, 1};
item_t superalloy_ammo_box            {false, false, 1};
item_t shell_set                      {false, false, 1};
item_t unipolar_magnet                {true, true, 0};

// Row 6
item_t engine                         {false, true, 1};
item_t thruster                       {false, true, 1};
item_t reinforced_thruster            {false, true, 1};
item_t super_magnetic_ring            {false, true, 1};
item_t particle_container             {false, true, 2};
item_t proliferator_mk3               {false, false, 1};
item_t prototype                      {false, false, 1};
item_t precision_drone                {false, false, 1};
item_t attack_drone                   {false, false, 1};
item_t corvette                       {false, false, 1};
item_t destroyer                      {false, false, 1};
item_t plasma_capsule                 {false, false, 1};
item_t high_explosive_shell_set       {false, false, 1};
item_t fire_ice                       {true, false, 0};

// Row 7
item_t logistics_bot                  {false, false, 1};
item_t logistics_drone                {false, false, 1};
item_t interstellar_logistics_vessel  {false, false, 1};
item_t space_warper                   {false, true, 2};
item_t graviton_lens                  {false, true, 1};
item_t foundation                     {false, true, 1};
item_t solar_sail                     {false, false, 1};
item_t frame_material                 {false, false, 1};
item_t dyson_sphere_component         {false, false, 1};
item_t small_carrier_rocket           {false, false, 1};
item_t antimatter_capsule             {false, false, 1};
item_t crystal_shell_set              {false, false, 1};
item_t log                            {true, true, 0};

// Row 8
item_t electromagnetic_matrix         {false, false, 1};
item_t energy_matrix                  {false, false, 1};
item_t structure_matrix               {false, false, 1};
item_t information_matrix             {false, false, 1};
item_t gravity_matrix                 {false, false, 1};
item_t universe_matrix                {false, false, 1};
item_t dark_fog_matrix                {false, true, 0};
item_t energy_shard                   {false, true, 0};
item_t silicon_based_neuron           {false, true, 0};
item_t negentropy_singularity         {false, true, 0};
item_t matter_recombinator            {false, true, 0};
item_t jamming_capsule                {false, false, 1};
item_t suppressing_capsule            {false, false, 1};
item_t plant_fuel                     {true, true, 0};

inline void initialize_recipes()
{
    // Row 1
	silicon_ore.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&stone, 10} }, 10.00, 1)
	));

	hydrogen.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&crude_oil, 2} }, 4.00, 1)
	));
	hydrogen.recipes.insert(std::make_pair(ADVANCED,
		set_recipe({ {&fire_ice, 2} }, 2.00, 1)
	));
	hydrogen.recipes.insert(std::make_pair(X_RAY_CRACKING,
		set_recipe({ {&refined_oil, 1}, {&hydrogen, 2} }, 4.00, 3)
	));
	hydrogen.recipes.insert(std::make_pair(MASS_ENERGY_STORAGE,
		set_recipe({ {&critical_photon, 2} }, 2.00, 2)
	));

	deuterium.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&hydrogen, 10} }, 2.50, 5)
	));

	antimatter.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&critical_photon, 2} }, 2.00, 2)
	));

	// Row 2
	iron_ingot.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&iron_ore, 1} }, 1.00, 1)
	));

	copper_ingot.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&copper_ore, 1} }, 1.00, 1)
	));

	stone_brick.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&stone, 1} }, 1.00, 1)
	));

	graphite.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&coal, 2} }, 2.00, 1)
	));
	graphite.recipes.insert(std::make_pair(ADVANCED, //X_RAY_CRACKLING
		set_recipe({ {&refined_oil, 1}, {&hydrogen, 2} }, 4.00, 1)
	));
	
	silicon_ingot.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&silicon_ore, 2} }, 2.00, 1)
	));

	titanium_ingot.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&titanium_ore, 2} }, 2.00, 1)
	));

	sulfuric_acid.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&refined_oil, 6}, {&stone, 8}, {&water, 4} },
		6.00, 4)
	));

	refined_oil.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&crude_oil, 2} }, 4.00, 2)
	));
	refined_oil.recipes.insert(std::make_pair(ADVANCED,
		set_recipe({ {&refined_oil, 2}, {&hydrogen, 1}, {&coal, 1} },
		4.00, 3)
	));

	hydrogen_fuel_rod.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&titanium_ingot, 1}, {&hydrogen, 10} }, 6.00, 2)
	));

	deuterium_fuel_rod.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&titanium_alloy, 1}, {&deuterium, 20}, 
					 {&super_magnetic_ring, 1} },
					 12.00, 2)
	));

	antimatter_fuel_rod.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&antimatter, 12}, {&hydrogen, 12}, 
					 {&annihilation_constraint_sphere, 1},
					 {&titanium_alloy, 1} },
					 24.00, 2)
	));

	strange_annihilation_fuel_rod.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&antimatter_fuel_rod, 8}, {&core_element, 1},
					 {&strange_matter, 2}, {&frame_material, 1} },
					 32.00, 1)
	));

	missile_set.recipes.insert(std::make_pair(MAIN,
		set_recipe({ {&copper_ingot, 6}, {&circuit_board, 3},
					 {&combustible_unit, 2}, {&engine, 1} },
					 2.00, 1)
	));

    // Row 3
    magnet.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ore, 1} }, 1.50, 1)
    ));

    magnetic_coil.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&magnet, 2}, {&copper_ingot, 1} }, 1.00, 2)
    ));

    glass.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&stone, 2} }, 2.00, 1)
    ));

    diamond.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graphite, 1} }, 2.00, 1)
    ));
    diamond.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&kimberlite_ore, 1} }, 1.50, 2)
    ));

    crystal_silicon.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&silicon_ingot, 1} }, 2.00, 1)
    ));
    crystal_silicon.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&fractal_silicon, 1} }, 1.50, 2)
    ));

    titanium_alloy.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&titanium_ingot, 4}, {&steel, 4}, 
					 {&sulfuric_acid, 8}}, 12.00, 4)
    ));

    combustible_unit.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&coal, 3} }, 3.00, 1)
    ));

    plastic.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&refined_oil, 2}, {&graphite, 1} }, 3.00, 1)
    ));

    organic_crystal.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&plastic, 2}, {&refined_oil, 1},
					 {&water, 1} }, 6.00, 1)
    ));
    organic_crystal.recipes.insert(std::make_pair(ADVANCED, // Not really
        set_recipe({ {&log, 20}, {&plant_fuel, 30},
					 {&water, 10} }, 6.00, 1)
    ));

    graphene.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graphite, 3}, {&sulfuric_acid, 1} }, 3.00, 2)
    ));
    graphene.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&fire_ice, 2} }, 2.00, 2)
    ));

    annihilation_constraint_sphere.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&particle_container, 1}, {&processor, 1} }, 20.00, 1)
    ));

    magnum_ammo_box.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&copper_ingot, 3} }, 1.00, 1)
    ));

    supersonic_missile_set.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&missile_set, 2}, {&processor, 4},
					 {&explosive_unit, 4}, {&thruster, 2} },
					 4.00, 2)
    ));
	
    // Row 4
    steel.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ingot, 3} }, 3.00, 1)
    ));

    circuit_board.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ingot, 2}, {&copper_ingot, 1} }, 1.00, 2)
    ));

    prism.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&glass, 3} }, 2.00, 2)
    ));

    electric_motor.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ingot, 2}, {&gear, 1},
					 {&magnetic_coil, 1} }, 2.00, 1)
    ));

    microcrystalline_component.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&silicon_ingot, 2}, {&copper_ingot, 1} }, 2.00, 1)
    ));

    proliferator_mk1.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&coal, 1} }, 0.50, 1)
    ));

    explosive_unit.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&combustible_unit, 2}, {&plastic, 2},
					 {&sulfuric_acid, 1} }, 6.00, 2)
    ));

    strange_matter.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&particle_container, 2}, {&iron_ingot, 2},
					 {&deuterium, 10} }, 8.00, 1)
    ));

    titanium_crystal.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&organic_crystal, 1}, {&titanium_ingot, 3} }, 4.00, 1)
    ));

    carbon_nanotubes.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graphite, 3}, {&titanium_ingot, 1} }, 4.00, 2)
    ));
    carbon_nanotubes.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&stalagmite_crystal, 6} }, 4.00, 2)
    ));

    particle_broadband.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&carbon_nanotubes, 2}, {&crystal_silicon, 2},
					 {&plastic, 1} }, 8.00, 1)
    ));

    titanium_ammo_box.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&magnum_ammo_box, 1}, {&titanium_ingot, 2} }, 2.00, 1)
    ));

    gravity_missile_set.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&supersonic_missile_set, 3}, {&crystal_explosive_unit, 6},
					 {&strange_matter, 3} }, 6.00, 3)
    ));

    // Row 5
    gear.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ingot, 1} }, 1.00, 1)
    ));

    plasma_exciter.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&magnetic_coil, 4}, {&prism, 2} }, 2.00, 1)
    ));

    photon_combiner.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&prism, 2}, {&circuit_board, 1} }, 3.00, 1)
    ));
    photon_combiner.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&grating_crystal, 1}, {&circuit_board, 1} }, 3.00, 1)
    ));

    electromagnetic_turbine.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&electric_motor, 2}, {&magnetic_coil, 2} }, 2.00, 1)
    ));

    processor.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&circuit_board, 2}, {&microcrystalline_component, 2} },
			          3.00, 1)
    ));

    proliferator_mk2.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&proliferator_mk1, 2}, {&diamond, 1} }, 1.00, 1)
    ));

    crystal_explosive_unit.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&explosive_unit, 8}, {&casimir_crystal, 1},
					 {&crystal_silicon, 8} }, 24.00, 8)
    ));

    casimir_crystal.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&titanium_crystal, 1}, {&graphene, 2},
					 {&hydrogen, 12} }, 4.00, 1)
    ));
    casimir_crystal.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&grating_crystal, 8}, {&graphene, 2},
					 {&hydrogen, 12} }, 4.00, 1)
    ));

    titanium_glass.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&glass, 2}, {&titanium_ingot, 2},
					 {&water, 2} }, 5.00, 2)
    ));

    plane_filter.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&casimir_crystal, 1}, {&titanium_glass, 2} },
					 12.00, 1)
    ));

    quantum_chip.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&processor, 2}, {&plane_filter, 2} }, 6.00, 1)
    ));

    superalloy_ammo_box.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&titanium_ammo_box, 1}, {&titanium_alloy, 1} },
					 3.00, 1)
    ));

    shell_set.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&copper_ingot, 9}, {&combustible_unit, 2} }, 1.50, 1)
    ));

    // Row 6
    engine.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&magnetic_coil, 1}, {&copper_ingot, 2} }, 3.00, 1)
    ));

    thruster.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&steel, 2}, {&copper_ingot, 3} }, 4.00, 1)
    ));

    reinforced_thruster.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&titanium_alloy, 5}, {&electromagnetic_turbine, 5} },
					 6.00, 1)
    ));

    super_magnetic_ring.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&electromagnetic_turbine, 2}, {&magnet, 3},
					 {&graphite, 1} }, 3.00, 1)
    ));

    particle_container.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&electromagnetic_turbine, 2}, {&copper_ingot, 2},
					 {&graphene, 2} }, 4.00, 1)
    ));
    particle_container.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&unipolar_magnet, 10}, {&copper_ingot, 2} }, 4.00, 1)
    ));

    proliferator_mk3.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&proliferator_mk2, 2}, {&carbon_nanotubes, 1} },
					 2.00, 1)
    ));

    prototype.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ingot, 3}, {&engine, 1},
					 {&circuit_board, 2}, {&plasma_exciter, 1} },
					 2.00, 1)
    ));

    precision_drone.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&prototype, 1}, {&electromagnetic_turbine, 1},
					 {&circuit_board, 2}, {&photon_combiner, 2} }, 
					 4.00, 1)
    ));

    attack_drone.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&precision_drone, 1}, {&electromagnetic_turbine, 1},
					 {&processor, 1}, {&particle_container, 1} },
					 4.00, 1)
    ));

    corvette.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&titanium_alloy, 5}, {&reinforced_thruster, 1},
					 {&processor, 2}, {&particle_container, 3} },
					 5.00, 1)
    ));

    destroyer.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&frame_material, 20}, {&reinforced_thruster, 4},
					 {&processor, 4}, {&strange_matter, 1} },
					 8.00, 1)
    ));

    plasma_capsule.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graphene, 1}, {&magnet, 2},
					 {&deuterium, 10} }, 2.00, 1)
    ));

    high_explosive_shell_set.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&shell_set, 1}, {&titanium_ingot, 6},
					 {&explosive_unit, 2} }, 3.00, 1)
    ));

    // Row 7
    logistics_bot.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ingot, 2}, {&engine, 1},
					 {&processor, 1} }, 2.00, 1)
    ));

    logistics_drone.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&iron_ingot, 5}, {&processor, 2},
					 {&thruster, 2} }, 4.00, 1)
    ));

    interstellar_logistics_vessel.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&titanium_alloy, 10}, {&processor, 10},
					 {&reinforced_thruster, 2} }, 6.00, 1)
    ));

    space_warper.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graviton_lens, 1} }, 10.00, 1)
    ));
    space_warper.recipes.insert(std::make_pair(ADVANCED,
        set_recipe({ {&gravity_matrix, 1} }, 10.00, 8)
    ));

    graviton_lens.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&diamond, 4}, {&strange_matter, 1} }, 6.00, 1)
    ));

    foundation.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&stone_brick, 3}, {&steel, 1} }, 1.00, 1)
    ));

    solar_sail.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graphene, 1}, {&photon_combiner, 1} }, 4.00, 2)
    ));

    frame_material.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&carbon_nanotubes, 4}, {&titanium_alloy, 1},
					 {&silicon_ingot, 1} }, 6.00, 1)
    ));

    dyson_sphere_component.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&frame_material, 3}, {&solar_sail, 3},
					 {&processor, 3} }, 8.00, 1)
    ));

    small_carrier_rocket.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&dyson_sphere_component, 2}, {&deuterium_fuel_rod, 4},
					 {&quantum_chip, 2} }, 6.00, 1)
    ));

    antimatter_capsule.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&plasma_capsule, 1}, {&particle_container, 1},
					 {&hydrogen, 10}, {&antimatter, 10} }, 
					 2.00, 1)
    ));

    crystal_shell_set.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&high_explosive_shell_set, 1}, {&titanium_alloy, 3},
					 {&crystal_explosive_unit, 2} }, 6.00, 1)
    ));

    // Row 8
    electromagnetic_matrix.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&magnetic_coil, 1}, {&circuit_board, 1} },
					 3.00, 1)
    ));

    energy_matrix.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graphite, 2}, {&hydrogen, 2} }, 6.00, 1)
    ));

    structure_matrix.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&diamond, 1}, {&titanium_crystal, 1} }, 8.00, 1)
    ));

    information_matrix.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&processor, 2}, {&particle_broadband, 1} }, 10.00, 1)
    ));

    gravity_matrix.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&graviton_lens, 1}, {&quantum_chip, 1} }, 24.00, 2)
    ));

    universe_matrix.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&electromagnetic_matrix, 1}, {&energy_matrix, 1},
					 {&structure_matrix, 1}, {&information_matrix, 1},
					 {&gravity_matrix, 1}, {&antimatter, 1} },
					 15.00, 1)
    ));

    jamming_capsule.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&electromagnetic_turbine, 1}, {&plasma_exciter, 1},
					 {&hydrogen, 3} }, 2.00, 1)
    ));

    suppressing_capsule.recipes.insert(std::make_pair(MAIN,
        set_recipe({ {&jamming_capsule, 2}, {&super_magnetic_ring, 1},
					 {&titanium_glass, 2} }, 8.00, 2)
    ));
}

inline void init_item_lookup() {
    // Row 1
    item_lookup["iron_ore"] = &iron_ore;
    item_lookup["copper_ore"] = &copper_ore;
    item_lookup["stone"] = &stone;
    item_lookup["coal"] = &coal;
    item_lookup["silicon_ore"] = &silicon_ore;
    item_lookup["titanium_ore"] = &titanium_ore;
    item_lookup["water"] = &water;
    item_lookup["crude_oil"] = &crude_oil;
    item_lookup["hydrogen"] = &hydrogen;
    item_lookup["deuterium"] = &deuterium;
    item_lookup["antimatter"] = &antimatter;
    item_lookup["core_element"] = &core_element;
    item_lookup["critical_photon"] = &critical_photon;
    item_lookup["kimberlite_ore"] = &kimberlite_ore;

    // Row 2
    item_lookup["iron_ingot"] = &iron_ingot;
    item_lookup["copper_ingot"] = &copper_ingot;
    item_lookup["stone_brick"] = &stone_brick;
    item_lookup["graphite"] = &graphite;
    item_lookup["silicon_ingot"] = &silicon_ingot;
    item_lookup["titanium_ingot"] = &titanium_ingot;
    item_lookup["sulfuric_acid"] = &sulfuric_acid;
    item_lookup["refined_oil"] = &refined_oil;
    item_lookup["hydrogen_fuel_rod"] = &hydrogen_fuel_rod;
    item_lookup["deuterium_fuel_rod"] = &deuterium_fuel_rod;
    item_lookup["antimatter_fuel_rod"] = &antimatter_fuel_rod;
    item_lookup["strange_annihilation_fuel_rod"] = &strange_annihilation_fuel_rod;
    item_lookup["missile_set"] = &missile_set;
    item_lookup["fractal_silicon"] = &fractal_silicon;

    // Row 3
    item_lookup["magnet"] = &magnet;
    item_lookup["magnetic_coil"] = &magnetic_coil;
    item_lookup["glass"] = &glass;
    item_lookup["diamond"] = &diamond;
    item_lookup["crystal_silicon"] = &crystal_silicon;
    item_lookup["titanium_alloy"] = &titanium_alloy;
    item_lookup["combustible_unit"] = &combustible_unit;
    item_lookup["plastic"] = &plastic;
    item_lookup["organic_crystal"] = &organic_crystal;
    item_lookup["graphene"] = &graphene;
    item_lookup["annihilation_constraint_sphere"] = &annihilation_constraint_sphere;
    item_lookup["magnum_ammo_box"] = &magnum_ammo_box;
    item_lookup["supersonic_missile_set"] = &supersonic_missile_set;
    item_lookup["grating_crystal"] = &grating_crystal;

    // Row 4
    item_lookup["steel"] = &steel;
    item_lookup["circuit_board"] = &circuit_board;
    item_lookup["prism"] = &prism;
    item_lookup["electric_motor"] = &electric_motor;
    item_lookup["microcrystalline_component"] = &microcrystalline_component;
    item_lookup["proliferator_mk1"] = &proliferator_mk1;
    item_lookup["explosive_unit"] = &explosive_unit;
    item_lookup["strange_matter"] = &strange_matter;
    item_lookup["titanium_crystal"] = &titanium_crystal;
    item_lookup["carbon_nanotubes"] = &carbon_nanotubes;
    item_lookup["particle_broadband"] = &particle_broadband;
    item_lookup["titanium_ammo_box"] = &titanium_ammo_box;
    item_lookup["gravity_missile_set"] = &gravity_missile_set;
    item_lookup["stalagmite_crystal"] = &stalagmite_crystal;

    //Row 5
    item_lookup["gear"] = &gear;
    item_lookup["plasma_exciter"] = &plasma_exciter;
    item_lookup["photon_combiner"] = &photon_combiner;
    item_lookup["electromagnetic_turbine"] = &electromagnetic_turbine;
    item_lookup["processor"] = &processor;
    item_lookup["proliferator_mk2"] = &proliferator_mk2;
    item_lookup["crystal_explosive_unit"] = &crystal_explosive_unit;
    item_lookup["casimir_crystal"] = &casimir_crystal;
    item_lookup["titanium_glass"] = &titanium_glass;
    item_lookup["plane_filter"] = &plane_filter;
    item_lookup["quantum_chip"] = &quantum_chip;
    item_lookup["superalloy_ammo_box"] = &superalloy_ammo_box;
    item_lookup["shell_set"] = &shell_set;
    item_lookup["unipolar_magnet"] = &unipolar_magnet;

    //Row 6
    item_lookup["engine"] = &engine;
    item_lookup["thruster"] = &thruster;
    item_lookup["reinforced_thruster"] = &reinforced_thruster;
    item_lookup["super_magnetic_ring"] = &super_magnetic_ring;
    item_lookup["particle_container"] = &particle_container;
    item_lookup["proliferator_mk3"] = &proliferator_mk3;
    item_lookup["prototype"] = &prototype;
    item_lookup["precision_drone"] = &precision_drone;
    item_lookup["attack_drone"] = &attack_drone;
    item_lookup["corvette"] = &corvette;
    item_lookup["destroyer"] = &destroyer;
    item_lookup["plasma_capsule"] = &plasma_capsule;
    item_lookup["high_explosive_shell_set"] = &high_explosive_shell_set;
    item_lookup["fire_ice"] = &fire_ice;

    //Row 7
    item_lookup["logistics_bot"] = &logistics_bot;
    item_lookup["logistics_drone"] = &logistics_drone;
    item_lookup["interstellar_logistics_vessel"] = &interstellar_logistics_vessel;
    item_lookup["space_warper"] = &space_warper;
    item_lookup["graviton_lens"] = &graviton_lens;
    item_lookup["foundation"] = &foundation;
    item_lookup["solar_sail"] = &solar_sail;
    item_lookup["frame_material"] = &frame_material;
    item_lookup["dyson_sphere_component"] = &dyson_sphere_component;
    item_lookup["small_carrier_rocket"] = &small_carrier_rocket;
    item_lookup["antimatter_capsule"] = &antimatter_capsule;
    item_lookup["crystal_shell_set"] = &crystal_shell_set;
    item_lookup["log"] = &log;

    //Row 8
    item_lookup["electromagnetic_matrix"] = &electromagnetic_matrix;
    item_lookup["energy_matrix"] = &energy_matrix;
    item_lookup["structure_matrix"] = &structure_matrix;
    item_lookup["information_matrix"] = &information_matrix;
    item_lookup["gravity_matrix"] = &gravity_matrix;
    item_lookup["universe_matrix"] = &universe_matrix;
    item_lookup["dark_fog_matrix"] = &dark_fog_matrix;
    item_lookup["energy_shard"] = &energy_shard;
    item_lookup["silicon_based_neuron"] = &silicon_based_neuron;
    item_lookup["negentropy_singularity"] = &negentropy_singularity;
    item_lookup["matter_recombinator"] = &matter_recombinator;
    item_lookup["jamming_capsule"] = &jamming_capsule;
    item_lookup["suppressing_capsule"] = &suppressing_capsule;
    item_lookup["plant_fuel"] = &plant_fuel;
}
// Macros
#ifdef KC_DSP_MACROS

struct matrix
{
	const item_t& blue = electromagnetic_matrix;
	const item_t& red = energy_matrix;
	const item_t& yellow = structure_matrix;
	const item_t& purple = information_matrix;
	const item_t& green = gravity_matrix;
	const item_t& white = universe_matrix;
	const item_t& fog = dark_fog_matrix;
};

struct combat
{
	const item_t& eu_1 = combustible_unit;
	const item_t& eu_2 = explosive_unit;
	const item_t& eu_3 = crystal_explosive_unit;
	const item_t& ab_1 = magnum_ammo_box;
	const item_t& ab_2 = titanium_ammo_box;
	const item_t& ab_3 = superalloy_ammo_box;
	const item_t& ms_1 = missile_set;
	const item_t& ms_2 = supersonic_missile_set;
	const item_t& ms_3 = gravity_missile_set;
	const item_t& ss_1 = shell_set;
	const item_t& ss_2 = high_explosive_shell_set;
	const item_t& ss_3 = crystal_shell_set;
	const item_t& jc_1 = jamming_capsule;
	const item_t& jc_2 = suppressing_capsule;
	const item_t& pc_1 = plasma_capsule;
	const item_t& pc_2 = antimatter_capsule;
};

struct spray
{
	const item_t& t1 = proliferator_mk1;
	const item_t& t2 = proliferator_mk2;
	const item_t& t3 = proliferator_mk3;
};

struct fog_craft_comp
{
	const item_t& t1 = silicon_based_neuron;
	const item_t& t2 = negentropy_singularity;
	const item_t& t3 = matter_recombinator;
	const item_t& t4 = core_element;
};

const item_t& micro_comp = microcrystalline_component;
const item_t& acid = sulfuric_acid;

#endif

} // namespace items
} // namespace dsp
