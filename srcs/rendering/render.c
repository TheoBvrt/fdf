/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/26 01:24:45 by theo             ###   ########.fr       */
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
		my_mlx_put_pixel(fdf->image, X, Y,  0xFF0000);
		X += Xinc;
		Y += Yinc;
		index ++;
	}
}

void	cricle_drawing(t_fdf *fdf, t_vec2 origin)
{
	double			i;
	double			x1;
	double			y1;
	double			angle;
	float			radius;
	radius = 2;

	while (radius >= 0)
	{
		i = 0;
		while (i < 360)
		{
			angle = i;
			x1 = radius * cos(angle * M_PI / 180);
			y1 = radius * sin(angle * M_PI / 180);
			my_mlx_put_pixel(fdf->image, origin.x + x1, origin.y + y1,  0xFF0000);
			i += 0.1;
		}
		radius --;
	}
}


void	fdf_rendering(t_fdf *fdf)
{
	t_vec2	screen_pos;
	t_vec2	end_line;
	t_vec2	tmp;
	t_vec2	tmp2;
	char			**tab;
	int				y;
	int				x;
	int				scale;

	tab = fdf->_heightmap;
	scale = 30;
	y = 0;

	float angle = 0.523599;

	float offset_x = (fdf->win_width / 2);
	float offset_y = (fdf->win_height / 2) - ((fdf->map_height / 2) * scale);

	fdf->map = rotate_matrix(fdf->map, fdf, 20, rotate_x);


	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			screen_pos.x = fdf->map[y][x].x * cos(angle) + fdf->map[y][x].y * cos(angle + 2) + fdf->map[y][x].z * cos(angle - 2);
			screen_pos.y = fdf->map[y][x].x  * sin(angle) + fdf->map[y][x].y * sin(angle + 2) + fdf->map[y][x].z * sin(angle - 2);
			
			tmp.x = (screen_pos.x * scale) + offset_x;
			tmp.y = (screen_pos.y * scale) + offset_y;
			cricle_drawing(fdf, tmp);
			if (x - 1 >= 0)
			{
				end_line.x = fdf->map[y][x - 1].x * cos(angle) + fdf->map[y][x - 1].y * cos(angle + 2) + fdf->map[y][x - 1].z * cos(angle - 2);
				end_line.y = fdf->map[y][x - 1].x  * sin(angle) + fdf->map[y][x - 1].y * sin(angle + 2) + fdf->map[y][x - 1].z * sin(angle - 2);
				tmp2.x = (end_line.x * scale) + offset_x;
				tmp2.y = (end_line.y * scale) + offset_y;
				dda_line(fdf, tmp, tmp2);	
			}

			if (y - 1 >= 0)
			{
				end_line.x = fdf->map[y - 1][x].x * cos(angle) + fdf->map[y - 1][x].y * cos(angle + 2) + fdf->map[y - 1][x].z * cos(angle - 2);
				end_line.y = fdf->map[y - 1][x].x  * sin(angle) + fdf->map[y - 1][x].y * sin(angle + 2) + fdf->map[y - 1][x].z * sin(angle - 2);
				tmp2.x = (end_line.x * scale) + offset_x;
				tmp2.y = (end_line.y * scale) + offset_y;
				dda_line(fdf, tmp, tmp2);
			}
			
			x ++;
		}
		y ++;
	}
}