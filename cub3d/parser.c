/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Forward declaration of get_next_line
char	*get_next_line(int fd);

// Simple function to read the map file
int	read_map_file(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Cannot open file %s\n", filename);
		return (-1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}

	close(fd);
	return (0);
}

// Check if a character is valid in the map
int	is_valid_element(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ')
		return (1);
	return (0);
}

// Validate the map structure
int	validate_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_element(map[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

// Find player starting position
int	find_player_start(char **map, int *x, int *y, char *dir)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || 
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				*x = j;
				*y = i;
				*dir = map[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}