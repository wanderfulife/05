/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24  by student                  #+#    #+#             */
/*   Updated: 2025/10/24  by student               ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Handle key press events
int	key_press(int keycode, void *param)
{
	(void)param;

	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	else if (keycode == KEY_W)
	{
		// Move forward
	}
	else if (keycode == KEY_S)
	{
		// Move backward
	}
	else if (keycode == KEY_A)
	{
		// Strafe left
	}
	else if (keycode == KEY_D)
	{
		// Strafe right
	}
	else if (keycode == KEY_LEFT)
	{
		// Rotate left
	}
	else if (keycode == KEY_RIGHT)
	{
		// Rotate right
	}
	return (0);
}

// Handle key release events
int	key_release(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	return (0);
}

// Handle mouse movement for looking around
int	mouse_move(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}