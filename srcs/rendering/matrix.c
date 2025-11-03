/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:00:26 by theo              #+#    #+#             */
/*   Updated: 2025/11/03 13:51:27 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	rotate_x(t_vec3 point, float angle)
{
	t_vec3	new;
	float	radian_angle;

	radian_angle = DEG_TO_RADIAN(angle);
	new.x = point.x;
	new.y = point.y * cos(radian_angle) - point.z * sin(radian_angle);
	new.z = point.y * sin(radian_angle) + point.z * cos(radian_angle);
	new.color = point.color;
	return (new);
}

t_vec3 rotate_y(t_vec3 point, float angle)
{
	t_vec3	new;
	float	radian_angle;

	radian_angle = DEG_TO_RADIAN(angle);
	new.x = point.x * cos(radian_angle) + point.z * sin(radian_angle);
	new.y = point.y;
	new.z = -point.x * sin(radian_angle) + point.z * cos(radian_angle);
	new.color = point.color;
	return (new);
}

t_vec3 rotate_z(t_vec3 point, float angle)
{
	t_vec3	new;
	float	radian_angle;

	radian_angle = DEG_TO_RADIAN(angle);
	new.x = point.x * cos(radian_angle) - point.y * sin(radian_angle);
	new.y = point.x * sin(radian_angle) + point.y * cos (radian_angle);
	new.z = point.z;
	new.color = point.color;
	return (new);
}

t_vec3 **rotate_matrix(t_vec3 **vec3_tab, t_fdf *fdf, float angle, t_vec3 (*f)(t_vec3, float))
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			vec3_tab[y][x] = f(vec3_tab[y][x], angle);
			x ++;
		}
		y ++;
	}
	return (vec3_tab);
}

void	reset_rotation(t_fdf *fdf)
{
	fdf->settings->roll = 0;
	fdf->settings->pitch = 0;
	fdf->settings->yaw = 0;
	fdf->settings->offset_x = (WIDTH / 3) + WIDTH * 0.25;
	fdf->settings->offset_y = (HEIGHT / 2);
	fdf->settings->height = 0.3;
}