/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:17:22 by theo              #+#    #+#             */
/*   Updated: 2025/11/07 00:16:35 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_point(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			fdf->map[y][x].y -= (fdf->map_height - 1) / 2;
			fdf->map[y][x].x -= (fdf->map_width - 1) / 2;
			x ++;
		}
		y ++;
	}
}

float	deg_to_radian(float x)
{
	return ((x) * M_PI / 180);
}
