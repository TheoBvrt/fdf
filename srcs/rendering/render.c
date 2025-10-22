/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/22 18:02:05 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	dda_line(t_fdf fdf, t_screen_pos start, t_screen_pos end)
{
	// float	x;
	// float	y;
	// float	dx;
	// float	dy;
	// float	step;
	// int		index;

	// index = 1;
	// dx = abs(end.x - start.x);
	// dy = abs(end.y - start.y);
	
	// if (dx >= dy)
	// 	step = dx;
	// else
	// 	step = dy;
	// dx /= step;
	// dy /= step;
	// x = start.x;
	// y = start.y;

	// while (index <= step)
	// {
	// 	mlx_pixel_put(fdf.mlx, fdf.mlx_win, x, y, 0xFF0000);
	// 	x += dx;
	// 	y += dy;
	// 	index ++;
	// }

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

void	cricle_drawing(t_fdf fdf, t_screen_pos origin)
{
	const double	PI = 3.1415926535;
	double			i;
	double			x1;
	double			y1;
	double			angle;
	float			radius;
	int	scale = 50;
	radius = 3;

	while (radius >= 0)
	{
		i = 0;
		while (i < 360)
		{
			angle = i;
			x1 = radius * cos(angle * PI / 180);
			y1 = radius * sin(angle * PI / 180);
			mlx_pixel_put(fdf.mlx, fdf.mlx_win, origin.x + x1, origin.y + y1, 0xFF0000);
			i += 0.1;
		}
		radius --;
	}
	
}

void	fdf_rendering(t_fdf fdf)
{
	t_point_pos		point;
	t_screen_pos	screen_pos;
	t_screen_pos	end_line;
	t_screen_pos	tmp;
	t_screen_pos	tmp2;
	char			**tab;
	int				y;
	int				x;
	int				scale;

	tab = fdf._heightmap;
	scale = 50;
	y = 0;

	int angle = 120;
	while (tab[y] != NULL)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			int z = tab[y][x] - 48;
			// screen_pos.x = x + cos(45) * tmp;
			// screen_pos.y = y + cos(45) * tmp;

			screen_pos.x = x * cos(angle) + y * cos(angle + 2) + z * cos(angle - 2);
			screen_pos.y = x * sin(angle) + y * sin(angle + 2) + z * sin(angle - 2);

			tmp.x = (screen_pos.x * scale) + 250;
			tmp.y = (screen_pos.y * scale) + 250;

				if (tab[y][x] == '2')
				{
					ft_printf (" x > %d", tmp.x);
					ft_printf ("y > %d\n", tmp.y);
				}


			cricle_drawing(fdf, tmp);

			if (x - 1 >= 0)
			{
				end_line.x = (x - 1) * cos(angle) + y * cos(angle + 2) + z * cos(angle - 2);
				end_line.y = (x - 1) * sin(angle) + y * sin(angle + 2) + z * sin(angle - 2);


				tmp2.x = (end_line.x * scale) + 250;
				tmp2.y = (end_line.y * scale) + 250;

								
				if (tab[y][x] == '2')
				{
					ft_printf (" x > %d", tmp2.x);
					ft_printf ("y > %d\n", tmp2.y);
				}
				dda_line(fdf, tmp, tmp2);
			}
			//mlx_pixel_put(fdf.mlx, fdf.mlx_win, (screen_pos.x * scale) + 250, (screen_pos.y * scale) + 250, 0xFF0000);
			x ++;
		}
		y ++;
	}
}