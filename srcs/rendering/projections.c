/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:33:07 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/05 18:23:44 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec3	apply_transformation(t_vec3 point, t_fdf *fdf, int apply_height)
{
	if (apply_height == 1)
		point.z *= fdf->settings->height;
	point = rotate_x(point, fdf->settings->roll);
	point = rotate_y(point, fdf->settings->pitch);
	point = rotate_z(point, fdf->settings->yaw);
	return (point);
}

static t_vec2	orthographic(t_vec3 vec3, t_fdf *fdf)
{
	t_vec2	screen_pos;

	vec3 = apply_transformation(vec3, fdf, 1);
	screen_pos.x = vec3.x * fdf->settings->scale + fdf->settings->offset_x;
	screen_pos.y = vec3.y * fdf->settings->scale + fdf->settings->offset_y;
	return (screen_pos);
}

static t_vec2	isometric(t_vec3 vec3, t_fdf *fdf)
{
	t_vec2	screen_pos;

	vec3 = apply_transformation(vec3, fdf, 1);
	screen_pos.x = vec3.x * cos(ANGLE) + vec3.y
		* cos(ANGLE + 2) + vec3.z * cos(ANGLE - 2);
	screen_pos.y = vec3.x * sin(ANGLE) + vec3.y
		* sin(ANGLE + 2) + vec3.z * sin(ANGLE - 2);
	screen_pos.x = (screen_pos.x * fdf->settings->scale)
		+ fdf->settings->offset_x;
	screen_pos.y = (screen_pos.y * fdf->settings->scale)
		+ fdf->settings->offset_y;
	return (screen_pos);
}

static	t_vec2	spheric(t_vec3 vec3, t_fdf *fdf, double y, double x)
{
	t_vec2	screen_pos;
	t_vec3	point;
	double	theta;
	double	phi;
	double	radius;

	theta = 2 * M_PI * (x / (fdf->map_width - 1));
	phi = M_PI * (y / (fdf->map_height - 1));
	vec3.z *= fdf->settings->height;
	radius = 300 + vec3.z * 5;
	vec3.x = radius * sin(phi) * cos(theta);
	vec3.y = radius * cos(phi);
	vec3.z = radius * sin(phi) * sin(theta);
	vec3 = apply_transformation(vec3, fdf, 0);
	screen_pos.x = (vec3.x *(fdf->settings->scale * 0.1))
		+ fdf->settings->offset_x;
	screen_pos.y = (vec3.y * (fdf->settings->scale * 0.1))
		+ fdf->settings->offset_y;
	return (screen_pos);
}

t_vec2	projection(t_vec3 vec3, t_fdf *fdf, int index[2])
{
	t_vec2	screen_pos;

	if (fdf->settings->projections == ISOMETRIC)
		screen_pos = isometric(vec3, fdf);
	else if (fdf->settings->projections == 3)
		screen_pos = spheric(vec3, fdf, (double)index[0], (double)index[1]);
	else
		screen_pos = orthographic(vec3, fdf);
	return (screen_pos);
}
