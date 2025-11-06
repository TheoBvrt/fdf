/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 23:47:19 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	dda_line(t_fdf *fdf, t_vec2 start, t_vec2 end, int colors[2])
{
	t_dda	dda;

	dda.i = 0;
	dda.dx = end.x - start.x;
	dda.dy = end.y - start.y;
	dda.s = abs(dda.dy);
	if ((!(start.x >= 0 && start.x <= WIDTH)
			|| !(start.y >= 0 && start.y <= HEIGHT))
		&& (!(end.x >= 0 && end.x <= WIDTH)
			|| !(end.y >= 0 && end.y <= HEIGHT)))
		return ;
	if (abs(dda.dx) > abs(dda.dy))
		dda.s = abs(dda.dx);
	dda.x_inc = dda.dx / (float)dda.s;
	dda.y_inc = dda.dy / (float)dda.s;
	dda.x = start.x;
	dda.y = start.y;
	while (dda.i <= dda.s)
	{
		dda.color = get_gradient(colors[1], colors[0], (float)dda.i / dda.s);
		my_mlx_put_pixel(fdf->image, dda.x, dda.y, dda.color);
		dda.x += dda.x_inc;
		dda.y += dda.y_inc;
		dda.i ++;
	}
}

static void	clear_screen(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	mlx_destroy_image(fdf->mlx, fdf->image->img);
	fdf->image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->image->addr = mlx_get_data_addr(fdf->image->img,
			&fdf->image->bits_per_pixel, &fdf->image->line_length,
			&fdf->image->endian);
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			my_mlx_put_pixel(fdf->image, x, y, PROJECTION_BACKGROUND);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
}

void	fdf_rendering(t_fdf *fdf)
{
	t_rendering	rd;

	rd.y = -1;
	clear_screen(fdf);
	while (++rd.y < fdf->map_height)
	{
		rd.x = -1;
		while (++rd.x < fdf->map_width)
		{
			rd.tmp = fdf->map[rd.y][rd.x];
			rd.start = projection(rd.tmp, fdf, (int []){rd.y, rd.x});
			if (rd.x - 1 >= 0)
				dda_line(fdf, rd.start, projection(fdf->map[rd.y][rd.x - 1],
						fdf, (int []){rd.y, rd.x - 1}),
					(int []){fdf->map[rd.y][rd.x - 1].color, rd.tmp.color});
			if (rd.y - 1 >= 0)
				dda_line(fdf, rd.start, projection(fdf->map[rd.y - 1][rd.x],
						fdf, (int []){rd.y - 1, rd.x}),
					(int []){fdf->map[rd.y - 1][rd.x].color, rd.tmp.color});
		}
	}
	draw_interface(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
	put_string(fdf);
}
