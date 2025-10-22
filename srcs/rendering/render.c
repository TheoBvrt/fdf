/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/22 13:42:19 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	bresenham_draw_line(t_fdf *fdf, t_pos start, t_pos end)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;
	int		index;

	index = 1;
	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	
	if (dx >= dy)
		step = dx;
	else
		step = dy;
	
	dx /= step;
	dy /= step;

	x = start.x;
	y = start.y;

	while (index <= step)
	{
		mlx_pixel_put(fdf->mlx, fdf->mlx_win, x, y, 0xFF0000);
		x += dx;
		y += dy;
		index ++;
	}
}

void fdf_rendering(t_fdf *fdf)
{
	t_pos	start;
	t_pos	end;

	start.x = 250;
	start.y = 250;

	end.x = 20;
	end.y = 200;
	
	bresenham_draw_line(fdf, start, end);
}