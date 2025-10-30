/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/30 17:33:26 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static void	dda_line(t_fdf *fdf, t_vec2 start, t_vec2 end, int color_b)
{
	int dx = end.x - start.x;
	int dy = end.y - start.y;

	int steps = abs(dy);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = start.x;
	float Y = start.y;
	int index = 0;
	while (index <= steps)
	{
		my_mlx_put_pixel(fdf->image, X, Y, color_b);
		X += Xinc;
		Y += Yinc;
		index ++;
	}
}

static void	clear_screen(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	mlx_destroy_image(fdf->mlx, fdf->image->img);
	fdf->image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->image->addr = mlx_get_data_addr(fdf->image->img, &fdf->image->bits_per_pixel, 
		&fdf->image->line_length, &fdf->image->endian);
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			my_mlx_put_pixel(fdf->image, x, y, 0x061021);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
}

void	fdf_rendering(t_fdf *fdf)
{
	t_vec2	screen_pos;
	t_vec2	end_line;
	int				y;
	int				x;
	y = 0;
	clear_screen(fdf);
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			screen_pos = isometric(fdf->map[y][x], fdf);
			if (x - 1 >= 0)
			{
				end_line = isometric(fdf->map[y][x - 1], fdf);
				dda_line(fdf, screen_pos, end_line, fdf->map[y][x -1].color);
			}

			if (y - 1 >= 0)
			{
				end_line = isometric(fdf->map[y - 1][x], fdf);
				dda_line(fdf, screen_pos, end_line, fdf->map[y - 1][x].color);
			}

			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
}
