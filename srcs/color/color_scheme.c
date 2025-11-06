/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:45:54 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 22:23:27 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	assign_color(t_fdf *fdf)
{
	float	tmp;
	int		color_range;
	int		x;
	int		y;

	y = 0;
	tmp = 0;
	color_range = fdf->max_height - fdf->min_height;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			tmp = (fdf->map[y][x].z + color_range - fdf->max_height) / color_range;
			tmp = get_gradient(DEFAULT_END_COLOR, DEFAULT_START_COLOR, tmp);
			fdf->map[y][x].color = tmp;
			x ++;
		}
		y ++;
	}
}

void	create_color_scheme(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			if (fdf->map[y][x].z < fdf->min_height)
				fdf->min_height = fdf->map[y][x].z;
			if (fdf->map[y][x].z > fdf->max_height)
				fdf->max_height = fdf->map[y][x].z;
			x ++;
		}
		y ++;
	}
	assign_color(fdf);
}