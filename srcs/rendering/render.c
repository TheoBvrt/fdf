/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/27 17:14:13 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	dda_line(t_fdf *fdf, t_vec2 start, t_vec2 end)
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
		my_mlx_put_pixel(fdf->image, X, Y,  0x2e808a);
		X += Xinc;
		Y += Yinc;
		index ++;
	}
}

void	clear_screen(t_fdf *fdf)
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
	t_vec2	tmp;
	t_vec2	tmp2;
	int				y;
	int				x;
	y = 0;

	clear_screen(fdf);
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			screen_pos.x = fdf->map[y][x].x * cos(ANGLE) + fdf->map[y][x].y * cos(ANGLE + 2) + fdf->map[y][x].z * cos(ANGLE - 2);
			screen_pos.y = fdf->map[y][x].x  * sin(ANGLE) + fdf->map[y][x].y * sin(ANGLE + 2) + fdf->map[y][x].z * sin(ANGLE - 2);
			
			tmp.x = (screen_pos.x * fdf->settings->scale) + fdf->settings->offset_x;
			tmp.y = (screen_pos.y * fdf->settings->scale) + fdf->settings->offset_y;
			if (x - 1 >= 0)
			{
				end_line.x = fdf->map[y][x - 1].x * cos(ANGLE) + fdf->map[y][x - 1].y * cos(ANGLE + 2) + fdf->map[y][x - 1].z * cos(ANGLE - 2);
				end_line.y = fdf->map[y][x - 1].x  * sin(ANGLE) + fdf->map[y][x - 1].y * sin(ANGLE + 2) + fdf->map[y][x - 1].z * sin(ANGLE - 2);
				tmp2.x = (end_line.x * fdf->settings->scale) + fdf->settings->offset_x;
				tmp2.y = (end_line.y * fdf->settings->scale) + fdf->settings->offset_y;
				dda_line(fdf, tmp, tmp2);
			}

			if (y - 1 >= 0)
			{
				end_line.x = fdf->map[y - 1][x].x * cos(ANGLE) + fdf->map[y - 1][x].y * cos(ANGLE + 2) + fdf->map[y - 1][x].z * cos(ANGLE - 2);
				end_line.y = fdf->map[y - 1][x].x  * sin(ANGLE) + fdf->map[y - 1][x].y * sin(ANGLE + 2) + fdf->map[y - 1][x].z * sin(ANGLE - 2);
				tmp2.x = (end_line.x * fdf->settings->scale) + fdf->settings->offset_x;
				tmp2.y = (end_line.y * fdf->settings->scale) + fdf->settings->offset_y;
				dda_line(fdf, tmp, tmp2);
			}

			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
}
