/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Put a single pixel to the image
void	my_mlx_pixel_put(void *mlx, void *win, int x, int y, int color)
{
	(void)mlx;
	(void)win;
	(void)x;
	(void)y;
	(void)color;
	// In a real implementation, this would put a pixel to the image
}

// Draw a rectangle (for testing purposes)
void	draw_rectangle(void *mlx, void *win, int x, int y, int width, int height, int color)
{
	int	i;
	int	j;

	i = y;
	while (i < y + height)
	{
		j = x;
		while (j < x + width)
		{
			my_mlx_pixel_put(mlx, win, j, i, color);
			j++;
		}
		i++;
	}
}

// Initialize the graphics
int	init_graphics(void *mlx, void *win)
{
	(void)mlx;
	(void)win;
	// Initialize any graphics-related data
	return (0);
}