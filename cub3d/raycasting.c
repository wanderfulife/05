/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PI 3.14159265359
#define FOV 60 * PI / 180  // Field of view in radians

// Raycasting function
void	cast_rays(void *mlx, void *win, t_player *player, char **map)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	x = 0;
	while (x < 900) // Screen width
	{
		// Calculate ray position and direction
		camera_x = 2 * x / (double)900 - 1; // x-coordinate in camera space
		ray_dir_x = player->dir_x + player->plane_x * camera_x;
		ray_dir_y = player->dir_y + player->plane_y * camera_x;
		
		// Which box of the map we're in
		map_x = (int)player->x;
		map_y = (int)player->y;
		
		// Length of ray from current position to next x or y-side
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		
		// Determine step direction and initial side distances
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (player->x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - player->x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (player->y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - player->y) * delta_dist_y;
		}
		
		// Perform DDA (Digital Differential Analysis)
		hit = 0;
		while (hit == 0)
		{
			// Jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			
			// Check if ray has hit a wall
			if (map[map_x][map_y] == '1')
				hit = 1;
		}
		
		// Calculate distance projected on camera direction
		if (side == 0)
			perp_wall_dist = (map_x - player->x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - player->y + (1 - step_y) / 2) / ray_dir_y;
		
		// Calculate height of line to draw on screen
		int line_height = (int)(600 / perp_wall_dist); // Screen height
		
		// Calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + 600 / 2; // Screen height / 2
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + 600 / 2; // Screen height / 2
		if (draw_end >= 600) // Screen height
			draw_end = 600 - 1; // Screen height - 1
		
		// Give x and y sides different colors
		int color;
		if (side == 1)
			color = 0xFF0000; // Red for y-side
		else
			color = 0x0000FF; // Blue for x-side
		
		// Draw the wall
		draw_rectangle(mlx, win, x, draw_start, 1, draw_end - draw_start, color);
		
		x++;
	}
}