/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:36 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/23 14:49:47 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_image image;
	t_fdf fdf;

	fdf.win_width = 1280;
	fdf.win_height = 720;
	if (!args_checker(argc, argv))
		return(1);
	if (!parse_map(argv[1], &fdf))
		return (1);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, fdf.win_width, fdf.win_height, "FdF");
	image.img = mlx_new_image(fdf.mlx, 1280, 720);


	// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
	// 	&image.line_length, &image.endian);
		
	// my_mlx_put_pixel(&image, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(&fdf.mlx, &fdf.mlx, &image.img, 0, 0);

	fdf_rendering(fdf);

	mlx_loop(fdf.mlx);
	exit (0);
}