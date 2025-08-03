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

## ⚠️ Notice ⚠️
 - Structures are not yet implemented.
 - Time display for assemblers and furnaces not yet implemented.
 - Filtering for "advanced" recipe use not yet implemented.