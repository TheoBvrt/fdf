/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:36:26 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/04 18:21:14 by thbouver         ###   ########.fr       */
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
	fake_bold(fdf, (t_vec2){TITLE_X, TITLE_X}, MAIN_COLOR, "// FILE DE FER, BY THBOUVER \\\\");
	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.09, MAIN_COLOR, "FILE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.09, ACCENT_COLOR, fdf->file_name);
	mlx_string_put(fdf->mlx, fdf->mlx_win, CATEGORIE_X_MARGIN, HEIGHT * 0.125, MAIN_COLOR, "SIZE : ");
	mlx_string_put(fdf->mlx, fdf->mlx_win, SUB_ITEM_MARGIN, HEIGHT * 0.125, ACCENT_COLOR, ft_itoa(fdf->map_height));
}

void	draw_interface(t_fdf *fdf)
{
	draw_rectangle(fdf, (t_vec2){0, 0}, (int []){HEIGHT, WIDTH * 0.25},
		INTERFACE_BACKGROUND);
}
