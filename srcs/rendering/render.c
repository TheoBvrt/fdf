/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/03 11:04:29 by thbouver         ###   ########.fr       */
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
	t_vec3 tmp;
	int				y;
	int				x;
	y = 0;
	clear_screen(fdf);
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			tmp = fdf->map[y][x];
			tmp.z *= fdf->settings->height;
			tmp = rotate_x(tmp, fdf->settings->roll);
			tmp = rotate_y(tmp, fdf->settings->pitch);
			tmp = rotate_z(tmp, fdf->settings->yaw);
			screen_pos = isometric(tmp, fdf);
			if (x - 1 >= 0)
			{
				tmp = fdf->map[y][x - 1];
				tmp.z *= fdf->settings->height;
				tmp = rotate_x(tmp, fdf->settings->roll);
				tmp = rotate_y(tmp, fdf->settings->pitch);
				tmp = rotate_z(tmp, fdf->settings->yaw);
				end_line = isometric(tmp, fdf);
				dda_line(fdf, screen_pos, end_line, tmp.color);
			}

			if (y - 1 >= 0)
			{
				tmp = fdf->map[y - 1][x];
				tmp.z *= fdf->settings->height;
				tmp = rotate_x(tmp, fdf->settings->roll);
				tmp = rotate_y(tmp, fdf->settings->pitch);
				tmp = rotate_z(tmp, fdf->settings->yaw);
				end_line = isometric(tmp, fdf);
				dda_line(fdf, screen_pos, end_line, tmp.color);
			}

			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
}
