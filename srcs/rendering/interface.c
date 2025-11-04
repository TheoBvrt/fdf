/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:36:26 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/04 23:24:55 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_rectangle(t_fdf *fdf, t_vec2 start, int size[2], int color)
{
	int	x;
	int	y;

	y = start.y;
	while (y < size[0])
	{
		x = start.x;
		while (x < size[1])
		{
			my_mlx_put_pixel(fdf->image, x, y, color);
			x ++;
		}
		y ++;
	}
}

static void	fake_bold(t_fdf *fdf, t_vec2 pos, int color, char *string)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, pos.x, pos.y, color, string);
	mlx_string_put(fdf->mlx, fdf->mlx_win, pos.x - 1, pos.y - 1, color, string);
}

void	put_string(t_fdf *fdf)
{
	mlx_set_font(fdf->mlx, fdf->mlx_win, TITLE_FONT);
	update_interface_data(fdf);
	fake_bold(fdf, (t_vec2){TITLE_X, TITLE_Y}, MAIN_COLOR, "// MAP INFOS \\\\");
	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.09, MAIN_COLOR, "FILE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.09, ACCENT_COLOR, fdf->data_interface.file_name);

	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.125, MAIN_COLOR, "SIZE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.125, ACCENT_COLOR, fdf->data_interface.map_size);

	fake_bold(fdf, (t_vec2){TITLE_X, HEIGHT * 0.190}, MAIN_COLOR, "// TRANSFORMATIONS \\\\");

	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.23, MAIN_COLOR, "OFFSETS : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.23, ACCENT_COLOR, fdf->data_interface.file_name);

	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.265, MAIN_COLOR, "ANGLE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.265, ACCENT_COLOR, fdf->data_interface.angle);

	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.3, MAIN_COLOR, "HEIGHT : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.3, ACCENT_COLOR, fdf->data_interface.file_name);

	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.335, MAIN_COLOR, "ZOOM : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.335, ACCENT_COLOR, fdf->data_interface.file_name);
}

void	draw_interface(t_fdf *fdf)
{
	draw_rectangle(fdf, (t_vec2){0, 0}, (int []){HEIGHT, WIDTH * 0.25},
		INTERFACE_BACKGROUND);
}
