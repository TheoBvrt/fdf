/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:36:26 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/03 15:01:09 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_rectangle(t_fdf *fdf, t_vec2 start, int size[2], int color)
{
	int	x;
	int	y;

	y = start.y;
	while (y < size[0])
	{
		x = start.x;
		while (x < size[1])
		{
			my_mlx_put_pixel(fdf->image, x, y, color);
			x ++;
		}
		y ++;
	}
}

void	draw_interface(t_fdf *fdf)
{
	draw_rectangle(fdf, (t_vec2){0, 0}, (int []){HEIGHT, WIDTH * 0.25}, 0x202020);
}
