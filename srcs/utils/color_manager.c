/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:02:04 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 17:03:00 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_rgb_color get_rgb_color(int color)
{
	t_rgb_color	rgb_color;

	rgb_color.r = (color >> 16) & 0xFF;
	rgb_color.g = (color >> 8) & 0xFF;
	rgb_color.b = color & 0xFF;
	return (rgb_color);
}

static int	create_color(t_rgb_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

int get_gradient(int c1, int c2, float t)
{
	t_rgb_color 	color_1;
	t_rgb_color		color_2;
	t_rgb_color		new;

	color_1 = get_rgb_color(c1);
	color_2 = get_rgb_color(c2);
	
	new.r = color_1.r + (color_2.r - color_1.r) * t;
	new.g = color_1.g + (color_2.g - color_1.g) * t;
	new.b = color_1.b + (color_2.b - color_1.b) * t;
	return (create_color(new));
}