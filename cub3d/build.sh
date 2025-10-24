#!/bin/bash

# Simple build script for cub3d

echo "Building cub3d project..."
make

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "To run with a map, use: ./cub3d map1.cub"
    echo "Available maps: map1.cub, map2.cub, map3.cub, map4.cub, map5.cub"
else
    echo "Build failed!"
fi