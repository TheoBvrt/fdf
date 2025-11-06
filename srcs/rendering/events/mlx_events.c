/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:46:15 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 23:00:40 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	on_keydown_2(int keycode, t_fdf *fdf)
{
	if (keycode == MINUS_KEY)
		fdf->settings.height -= 0.1;
	if (keycode == PLUS_KEY)
		fdf->settings.height += 0.1;
	if (keycode == ESCAPE)
		clean_program(fdf);
	if (keycode == R_KEY)
		reset_settings(fdf);
}

int	on_keydown(int keycode, t_fdf *fdf)
{
	if (keycode == UP_ARROW)
		fdf->settings.roll += 5;
	if (keycode == DOWN_ARROW)
		fdf->settings.roll -= 5;
	if (keycode == LEFT_ARROW)
		fdf->settings.pitch -= 5;
	if (keycode == RIGHT_ARROW)
		fdf->settings.pitch += 5;
	if (keycode == W_KEY)
		fdf->settings.offset_y -= 10;
	if (keycode == S_KEY)
		fdf->settings.offset_y += 10;
	if (keycode == A_KEY)
		fdf->settings.offset_x -= 10;
	if (keycode == D_KEY)
		fdf->settings.offset_x += 10;
	on_keydown_2(keycode, fdf);
	fdf_rendering(fdf);
	return (1);
}

int	on_mouse_down(int keycode, int x, int y, t_fdf *fdf)
{
	if (keycode == LEFT_CLICK || keycode == RIGHT_CLICK)
		find_button(fdf, x, y);
	if (keycode == SCROLL_UP)
		fdf->settings.scale += 2;
	if (keycode == SCROLL_DOWN && fdf->settings.scale >= 2)
		fdf->settings.scale -= 2;
	fdf_rendering(fdf);
	return (1);
}

int	on_cross_click(t_fdf *fdf)
{
	clean_program(fdf);
	return (1);
}
