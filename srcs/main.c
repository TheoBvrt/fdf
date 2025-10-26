/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:36 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/25 22:30:54 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_image image;
	t_fdf fdf;

	fdf.win_width = 1280;
	fdf.win_height = 720;
	fdf.map = NULL;
	if (!args_checker(argc, argv))
		return(1);
	if (!parse_map(argv[1], &fdf))
		return (1);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, fdf.win_width, fdf.win_height, "FdF");
	image.img = mlx_new_image(fdf.mlx, 1280, 720);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
		&image.line_length, &image.endian);
	fdf.image = &image;

	fdf_rendering(&fdf);

	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.image->img, 0, 0);
	mlx_loop(fdf.mlx);
	//free_vec3_tab(fdf.map, fdf.map_height);
	exit (0);
}