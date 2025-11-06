/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:52:35 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/07 00:16:49 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fake_bold(t_fdf *fdf, t_vec2 pos, int color, char *string)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, pos.x, pos.y, color, string);
	mlx_string_put(fdf->mlx, fdf->mlx_win, pos.x - 1, pos.y - 1, color, string);
}

void	put_string_infos(t_fdf *fdf)
{
	fake_bold(fdf, (t_vec2){WIDTH * 0.035, HEIGHT * 0.05},
		MAIN_COLOR, "MAP INFOS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.09, MAIN_COLOR, "FILE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.09, ACCENT_COLOR, fdf->data_interface.file_name);
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.125, MAIN_COLOR, "SIZE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.125, ACCENT_COLOR, fdf->data_interface.map_size);
}

void	put_string_transformations(t_fdf *fdf)
{
	fake_bold(fdf, (t_vec2){WIDTH * 0.035, HEIGHT * 0.190},
		MAIN_COLOR, "TRANSFORMATIONS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.23, MAIN_COLOR, "OFFSETS : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.23, ACCENT_COLOR, fdf->data_interface.offsets);
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.265, MAIN_COLOR, "ANGLE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.265, ACCENT_COLOR, fdf->data_interface.angle);
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.3, MAIN_COLOR, "HEIGHT : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.3, ACCENT_COLOR, fdf->data_interface.height_scale);
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.335, MAIN_COLOR, "ZOOM : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.335, ACCENT_COLOR, fdf->data_interface.scale);
}

void	put_string_projections(t_fdf *fdf)
{
	fake_bold(fdf, (t_vec2){WIDTH * 0.035, HEIGHT * 0.425},
		MAIN_COLOR, "PROJECTIONS");
	fake_bold(fdf, (t_vec2){WIDTH * 0.05
		+ (WIDTH * 0.012), HEIGHT * 0.482},
		ACCENT_COLOR, "SPHERIC");
	fake_bold(fdf, (t_vec2){WIDTH * 0.05
		+ (WIDTH * 0.088), HEIGHT * 0.482},
		ACCENT_COLOR, "ORTHOGRAPHIC");
	fake_bold(fdf, (t_vec2){WIDTH * 0.05
		+ (WIDTH * 0.051), HEIGHT * 0.534},
		ACCENT_COLOR, "ISOMETRIC");
}

void	put_string_control(t_fdf *fdf)
{
	fake_bold(fdf, (t_vec2){WIDTH * 0.035, HEIGHT * 0.63},
		MAIN_COLOR, "CONTROLS");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.67, MAIN_COLOR, "SHIFT : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.67, ACCENT_COLOR, "W A S D");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.71, MAIN_COLOR, "ROTATION : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.71, ACCENT_COLOR, "UP/DOWN/LEFT/RIGHT ARROW");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.75, MAIN_COLOR, "ZOOM +/-: ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.75, ACCENT_COLOR, "SCROLL UP/SCROLL DOWN");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.79, MAIN_COLOR, "HEIGHT +/-: ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.79, ACCENT_COLOR, "+/-");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.05, HEIGHT
		* 0.83, MAIN_COLOR, "RESET : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIDTH * 0.12, HEIGHT
		* 0.83, ACCENT_COLOR, "R");
}
