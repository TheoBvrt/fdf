/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:00:26 by theo              #+#    #+#             */
/*   Updated: 2025/10/23 15:10:14 by theo             ###   ########.fr       */
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
	return (new);
}