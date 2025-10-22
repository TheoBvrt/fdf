/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:36 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/22 16:55:02 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_image image;
	t_fdf fdf;
	

	if (!args_checker(argc, argv))
		return(1);
	if (!parse_map(argv[1], &fdf))
		return (1);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, 1920, 1080, "FdF");

	// image.img = mlx_new_image(fdf.mlx, 1280, 720);


	// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
	// 	&image.line_length, &image.endian);
		
	// my_mlx_put_pixel(&image, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(&fdf.mlx, &fdf.mlx, &image.img, 0, 0);

	fdf_rendering(fdf);

	mlx_loop(fdf.mlx);
	exit (0);
}