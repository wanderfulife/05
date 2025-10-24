/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	// Handle key presses here
	return (0);
}

int	close_hook(t_data *data)
{
	(void)data;
	printf("Game closed.\n");
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Usage: %s <map_file.cub>\n", argv[0]);
		return (1);
	}

	// Initialize MLX
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		printf("Error: Failed to initialize MLX\n");
		return (1);
	}

	// Create window
	data.win = mlx_new_window(data.mlx, 900, 600, "Cub3D");
	if (!data.win)
	{
		printf("Error: Failed to create window\n");
		return (1);
	}

	// Set up hooks
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_hook, &data); // Window close button

	// Display a message
	printf("Loading map: %s\n", argv[1]);

	// Start the game loop
	mlx_loop(data.mlx);

	return (0);
}