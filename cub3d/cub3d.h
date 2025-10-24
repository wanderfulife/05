/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

// Define keyboard keys for different systems
#ifdef __APPLE__
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
#else
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
#endif

// Structure definitions
typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

// Function prototypes
// parser.c
int		read_map_file(char *filename);
int		is_valid_element(char c);
int		validate_map(char **map);
int		find_player_start(char **map, int *x, int *y, char *dir);

// map_validator.c
int		is_map_surrounded(char **map);
int		has_valid_path(char **map, int start_x, int start_y);
int		validate_complete_map(char **map);

// utils.c
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// texture_utils.c
t_texture	load_texture(void *mlx, char *path);
int			get_texture_color(t_texture tex, int x, int y);

// events.c
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
int		mouse_move(int x, int y, void *param);

// graphics.c
void	my_mlx_pixel_put(void *mlx, void *win, int x, int y, int color);
void	draw_rectangle(void *mlx, void *win, int x, int y, int width, int height, int color);
int		init_graphics(void *mlx, void *win);

// raycasting.c
void	cast_rays(void *mlx, void *win, t_player *player, char **map);

#endif