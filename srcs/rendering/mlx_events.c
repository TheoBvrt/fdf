/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:46:15 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/03 13:11:08 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_keydown(int keycode, t_fdf *fdf)
{
	if (keycode == UP_ARROW)
		fdf->settings->roll += 5;	
	if (keycode == DOWN_ARROW)
		fdf->settings->roll -= 5;
	if (keycode == LEFT_ARROW)
		fdf->settings->pitch -= 5;
	if (keycode == RIGHT_ARROW)
		fdf->settings->pitch += 5;
	if (keycode == W_KEY)
		fdf->settings->offset_y -= 10;
	if (keycode == S_KEY)
		fdf->settings->offset_y += 10;
	if (keycode == A_KEY)
		fdf->settings->offset_x -= 10;
	if (keycode == D_KEY)
		fdf->settings->offset_x += 10;
	if (keycode == MINUS_KEY)
		fdf->settings->height -= 0.1;	
	if (keycode == PLUS_KEY)
		fdf->settings->height += 0.1;
	if (keycode == ESCAPE)
		clean_program(fdf);
	if (keycode == R_KEY)
		reset_rotation(fdf);
	fdf_rendering(fdf);
	return (1);
}

int	on_mouseDown(int keycode, int x, int y, t_fdf *fdf)
{
	if (keycode == SCROLL_UP)
		fdf->settings->scale += 2;
	if (keycode == SCROLL_DOWN && fdf->settings->scale >= 2)
		fdf->settings->scale -= 2;;
	fdf_rendering(fdf);
	return (1);
}

int	on_cross_click(t_fdf *fdf)
{
	clean_program(fdf);
}
