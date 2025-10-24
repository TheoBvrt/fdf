/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/24 17:57:19 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	dda_line(t_fdf fdf, t_vec2 start, t_vec2 end)
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
		mlx_pixel_put(fdf.mlx, fdf.mlx_win, X, Y, 0xFF0000);
		X += Xinc;
		Y += Yinc;
		index ++;
	}
}

void	cricle_drawing(t_fdf fdf, t_vec2 origin)
{
	double			i;
	double			x1;
	double			y1;
	double			angle;
	float			radius;
	radius = 1;

	while (radius >= 0)
	{
		i = 0;
		while (i < 360)
		{
			angle = i;
			x1 = radius * cos(angle * M_PI / 180);
			y1 = radius * sin(angle * M_PI / 180);
			mlx_pixel_put(fdf.mlx, fdf.mlx_win, origin.x + x1, origin.y + y1, 0xFF0000);
			i += 0.1;
		}
		radius --;
	}
}


void	fdf_rendering(t_fdf fdf)
{
	t_vec2	screen_pos;
	t_vec2	end_line;
	t_vec2	tmp;
	t_vec2	tmp2;
	char			**tab;
	int				y;
	int				x;
	int				scale;

	tab = fdf._heightmap;
	scale = 50;
	y = 0;

	float new_angle = 0;
	float angle = 0.523599;

	while (y < fdf.map_height)
	{
		x = 0;
		while (x < fdf.map_width)
		{
			screen_pos.x = fdf.map[y][x].x * cos(angle) + fdf.map[y][x].y * cos(angle + 2) + fdf.map[y][x].z * cos(angle - 2);
			screen_pos.y = fdf.map[y][x].x  * sin(angle) + fdf.map[y][x].y * sin(angle + 2) + fdf.map[y][x].z * sin(angle - 2);

			tmp.x = (screen_pos.x * scale) + ((fdf.win_width / 2) / 2);
			tmp.y = (screen_pos.y * scale) + ((fdf.win_height / 2) / 2);
		
			if (x - 1 >= 0)
			{
				end_line.x = fdf.map[y][x - 1].x * cos(angle) + fdf.map[y][x - 1].y * cos(angle + 2) + fdf.map[y][x - 1].z * cos(angle - 2);
				end_line.y = fdf.map[y][x - 1].x  * sin(angle) + fdf.map[y][x - 1].y * sin(angle + 2) + fdf.map[y][x - 1].z * sin(angle - 2);
				tmp2.x = (end_line.x * scale) + ((fdf.win_width / 2) / 2);
				tmp2.y = (end_line.y * scale) + ((fdf.win_height / 2) / 2);
				dda_line(fdf, tmp, tmp2);	
			}

			if (y - 1 >= 0)
			{
				end_line.x = fdf.map[y - 1][x].x * cos(angle) + fdf.map[y - 1][x].y * cos(angle + 2) + fdf.map[y - 1][x].z * cos(angle - 2);
				end_line.y = fdf.map[y - 1][x].x  * sin(angle) + fdf.map[y - 1][x].y * sin(angle + 2) + fdf.map[y - 1][x].z * sin(angle - 2);
				tmp2.x = (end_line.x * scale) + ((fdf.win_width / 2) / 2);
				tmp2.y = (end_line.y * scale) + ((fdf.win_height / 2) / 2);
				dda_line(fdf, tmp, tmp2);
			}
			
			x ++;
		}
		y ++;
	}

	// while (tab[y] != NULL)
	// {
	// 	x = 0;
	// 	while (tab[y][x] != '\0')
	// 	{

	// 		t_vec3 point;

	// 		point.x = x;
	// 		point.y = y;
	// 		point.z = tab[y][x] - 48;

	// 		point = rotate_x(point, new_angle);

	// 		screen_pos.x = point.x * cos(angle) + point.y * cos(angle + 2) + point.z * cos(angle - 2);
	// 		screen_pos.y = point.x * sin(angle) + point.y * sin(angle + 2) + point.z * sin(angle - 2);

	// 		tmp.x = (screen_pos.x * scale) + ((fdf.win_width / 2) / 2);
	// 		tmp.y = (screen_pos.y * scale) + ((fdf.win_height / 2) / 2);
		
	// 		cricle_drawing(fdf, tmp);

	// 		if (x - 1 >= 0)
	// 		{

	// 			point.x = x - 1;
	// 			point.y = y;
	// 			point.z = tab[y][x - 1] - 48;
	// 			point = rotate_x(point, new_angle);

	// 			end_line.x = point.x * cos(angle) + point.y * cos(angle + 2) + point.z * cos(angle - 2);
	// 			end_line.y = point.x * sin(angle) + point.y * sin(angle + 2) + point.z * sin(angle - 2);
	// 			tmp2.x = (end_line.x * scale) + ((fdf.win_width / 2) / 2);
	// 			tmp2.y = (end_line.y * scale) + ((fdf.win_height / 2) / 2);
	// 			dda_line(fdf, tmp, tmp2);
	// 		}


	// 		if (y - 1 >= 0)
	// 		{
	// 			point.x = x;
	// 			point.y = y - 1;
	// 			point.z = tab[y - 1][x] - 48;
	// 			point = rotate_x(point, new_angle);

	// 			end_line.x = point.x * cos(angle) + point.y * cos(angle + 2) + point.z * cos(angle - 2);
	// 			end_line.y = point.x * sin(angle) + point.y * sin(angle + 2) + point.z * sin(angle - 2);
	// 			tmp2.x = (end_line.x * scale) + ((fdf.win_width / 2) / 2);
	// 			tmp2.y = (end_line.y * scale) + ((fdf.win_height / 2) / 2);
	// 			dda_line(fdf, tmp, tmp2);
	// 		}

	// 		mlx_pixel_put(fdf.mlx, fdf.mlx_win, (screen_pos.x * scale) + 250, (screen_pos.y * scale) + 250, 0xFF0000);
	// 		x ++;
	// 	}
	// 	y ++;
	// }
}