# dspCraft CLI (Version 0.1)

A (as of right now) basic command-line tool to explore crafting recipe trees for *Dyson Sphere Program*. 

## Build Instructions

```bash
git clone https://github.com/kcExperts/dspCraft.git dspCraft
cd dspCraft
mkdir build && cd build
cmake ..
cmake --build
```

## Basic Usage

```bash
./dspCraft --craft iron_ingot
```

See `-h` or `--help` for more information. 

To see all the items you can use (as well as the names):
```bash
./dspCraft --list items
```

## Example Outputs
```bash
./dspCraft -c missile_set -m 60 -b 1
```

Produces:
```
Craft info for: missile_set
  - Target: 60 per minute
  - Raw Materials/belt:
    1.00x belt (MK1) for coal (harvestable)
    1.33x belt (MK1) for iron_ore (harvestable)
    2.00x belt (MK1) for copper_ore (harvestable)
```
----
```bash
./dspCraft -c missile_set -m 60 -d 2
```

Produces:
```
Craft info for: missile_set
  - Target: 60 per minute
  - Raw Materials/min:
    60.00x magnetic_coil
    360.00x coal (harvestable)
    300.00x copper_ingot
    360.00x iron_ingot
    360.00x copper_ore (harvestable)
```


## ⚠️ Notice ⚠️
 - Structures are not yet implemented.
 - Time display for assemblers and furnaces not yet implemented.
 - Filtering for "advanced" recipe use not yet implemented.