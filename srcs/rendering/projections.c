/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:33:07 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/30 17:34:09 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	isometric(t_vec3 vec3, t_fdf *fdf)
{
	t_vec2	pos;

	pos.x = vec3.x * cos(ANGLE) + vec3.y * cos(ANGLE + 2) + vec3.z * cos(ANGLE - 2);
	pos.y = vec3.x * sin(ANGLE) + vec3.y * sin(ANGLE + 2) + vec3.z * sin(ANGLE - 2);
	pos.x = (pos.x * fdf->settings->scale) + fdf->settings->offset_x;
	pos.y = (pos.y * fdf->settings->scale) + fdf->settings->offset_y;
	return (pos);
}