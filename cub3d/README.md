# Cub3D - 42 Project

Cub3D is the first graphical project in the 42 curriculum, implementing a raycaster engine similar to Wolfenstein 3D.

## Project Structure

```
cub3d/
├── main.c          # Main entry point and MLX window setup
├── parser.c        # Map parsing and validation
├── get_next_line.c # Line reading utility
├── map_validator.c # Map validation functions
├── raycasting.c    # Raycasting algorithm implementation
├── texture_utils.c # Texture loading and handling
├── graphics.c      # Graphics utility functions
├── events.c        # Keyboard and mouse event handling
├── utils.c         # Utility functions
├── cub3d.h         # Header file with definitions and prototypes
├── Makefile        # Build configuration
├── build.sh        # Quick build script
├── map1.cub        # Sample map 1
├── map2.cub        # Sample map 2
├── map3.cub        # Sample map 3
├── map4.cub        # Sample map 4
└── map5.cub        # Sample map 5
```

## Map File Format

The `.cub` files contain the map definition with these elements:

- `NO`, `SO`, `WE`, `EA` - Paths to texture files for each direction
- `F` - Floor RGB color (e.g., `F 220,100,50`)
- `C` - Ceiling RGB color (e.g., `C 100,150,200`)
- `1` - Wall
- `0` - Empty space
- `N`, `S`, `E`, `W` - Player starting position and orientation

## Building the Project

1. Install minilibx (MLX) if not already available
2. Run `make` to compile the project
3. Use the build script: `./build.sh`

## Running with Maps

```bash
./cub3d map1.cub
```

Available maps: map1.cub through map5.cub

## Controls

- W, A, S, D - Movement
- Arrow keys - Rotation
- ESC - Quit

## Requirements

- Linux or macOS
- X11 development libraries
- minilibx (MLX) graphics library
- GCC compiler

## About the Maps

Each map file is designed with different complexities:

1. **map1.cub** - Simple rectangular room to test basic functionality
2. **map2.cub** - Room with corridor to test wall detection
3. **map3.cub** - Multiple connected rooms to test complex navigation
4. **map4.cub** - Complex layout with internal walls
5. **map5.cub** - Different player starting orientation (facing East)