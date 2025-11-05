/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:36:26 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/05 17:59:12 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_string(t_fdf *fdf)
{
	update_interface_data(fdf);
	put_string_infos(fdf);
	put_string_transformations(fdf);
	put_string_projections(fdf);
	put_string_control(fdf);
}

void	draw_rectangle(t_fdf *fdf, t_vec2 start, int size[2], int color)
{
	int	x;
	int	y;

	y = start.y;
	while (y < (size[1] + start.y))
	{
		x = start.x;
		while (x < (size[0] + start.x))
		{
			my_mlx_put_pixel(fdf->image, x, y, color);
			x ++;
		}
		y ++;
	}
}

void	draw_interface(t_fdf *fdf)
{
	draw_rectangle(fdf, (t_vec2){0, 0}, (int []){WIDTH * 0.25, HEIGHT},
		INTERFACE_BACKGROUND);
	display_button(fdf);
}
