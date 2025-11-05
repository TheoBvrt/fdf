/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:18:52 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/05 15:03:16 by thbouver         ###   ########.fr       */
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
	free(fdf->data_interface.map_size);
	free(fdf->data_interface.angle);
	free(fdf->data_interface.height_scale);
	free(fdf->data_interface.scale);
	free(fdf->data_interface.offsets);
	exit(1);
}