/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:46:15 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/28 16:03:39 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_keydown(int keycode, t_fdf *fdf)
{
	if (keycode == UP_ARROW)
		rotate_matrix(fdf->map, fdf, 5, rotate_x);
	if (keycode == DOWN_ARROW)
		rotate_matrix(fdf->map, fdf, -5, rotate_x);
	if (keycode == LEFT_ARROW)
		rotate_matrix(fdf->map, fdf, -5, rotate_y);
	if (keycode == RIGHT_ARROW)
		rotate_matrix(fdf->map, fdf, 5, rotate_y);
	if (keycode == W_KEY)
		fdf->settings->offset_y -= 10;
	if (keycode == S_KEY)
		fdf->settings->offset_y += 10;
	if (keycode == A_KEY)
		fdf->settings->offset_x -= 10;
	if (keycode == D_KEY)
		fdf->settings->offset_x += 10;
	fdf_rendering(fdf);
	return (1);
}

int	on_mouseDown(int keycode, int x, int y, t_fdf *fdf)
{
	if (keycode == SCROLL_UP)
		fdf->settings->scale += 2;
	if (keycode == SCROLL_DOWN && fdf->settings->scale >= 2)
		fdf->settings->scale -= 2;
	fdf_rendering(fdf);
	return (1);
}
