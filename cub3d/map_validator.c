/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if the map is surrounded by walls
int	is_map_surrounded(char **map)
{
	int	i;
	int	rows;
	int	cols;

	// Count rows
	rows = 0;
	while (map[rows])
		rows++;
	
	// Count columns in first row (assuming rectangular map)
	cols = 0;
	if (map[0])
	{
		while (map[0][cols] && map[0][cols] != '\n')
			cols++;
	}

	// Check top and bottom rows
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}

	// Check leftmost and rightmost columns
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}

	return (1);
}

// Check if there's a valid path from player position to the outside
int	has_valid_path(char **map, int start_x, int start_y)
{
	// This would implement flood-fill or similar algorithm
	// to check if player can escape or if there are no unreachable areas
	(void)map;
	(void)start_x;
	(void)start_y;
	return (1); // Simplified for this example
}

// Validate all aspects of the map
int	validate_complete_map(char **map)
{
	int	player_x;
	int	player_y;
	char	player_dir;

	// Find player
	if (!find_player_start(map, &player_x, &player_y, &player_dir))
	{
		printf("Error: No player start position found (N, S, E, or W)\n");
		return (-1);
	}

	// Check if map is surrounded by walls
	if (!is_map_surrounded(map))
	{
		printf("Error: Map is not surrounded by walls\n");
		return (-1);
	}

	// Check for valid path
	if (!has_valid_path(map, player_x, player_y))
	{
		printf("Error: Invalid map path\n");
		return (-1);
	}

	return (0);
}