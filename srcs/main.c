/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:36 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/27 11:41:02 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_image image;
	t_fdf fdf;

	fdf.win_width = 1920;
	fdf.win_height = 1080;
	fdf.map = NULL;
	if (!args_checker(argc, argv))
		return(1);
	if (!parse_map(argv[1], &fdf))
		return (1);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, fdf.win_width, fdf.win_height, "FdF");
	image.img = mlx_new_image(fdf.mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
		&image.line_length, &image.endian);
	fdf.image = &image;

	fdf_rendering(&fdf);

	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.image->img, 0, 0);
	
	mlx_hook(fdf.mlx_win, 2, (1L<<0), on_keydown, &fdf);
	mlx_hook(fdf.mlx_win, 4, (1L<<2), on_mouseDown, &fdf);
	
	mlx_loop(fdf.mlx);
	//free_vec3_tab(fdf.map, fdf.map_height);
	exit (0);
}