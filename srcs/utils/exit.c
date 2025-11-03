/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:18:52 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/03 12:43:15 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_program(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image->img);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free_vec3_tab(fdf->map, fdf->map_height);
	exit(1);
}