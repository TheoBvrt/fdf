/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:36:42 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/03 23:16:33 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}