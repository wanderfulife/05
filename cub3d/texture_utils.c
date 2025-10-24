/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Load texture from file
t_texture	load_texture(void *mlx, char *path)
{
	t_texture	texture;
	
	texture.img = mlx_xpm_file_to_image(mlx, path, &texture.width, &texture.height);
	if (!texture.img)
	{
		texture.addr = NULL;
		texture.width = 0;
		texture.height = 0;
		return (texture);
	}
	texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel,
									&texture.line_length, &texture.endian);
	return (texture);
}

// Get color from texture at specific coordinates
int	get_texture_color(t_texture tex, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || x >= tex.width || y < 0 || y >= tex.height)
		return (0);
	pixel = tex.addr + (y * tex.line_length + x * (tex.bits_per_pixel / 8));
	color = *(int *)pixel;
	return (color);
}