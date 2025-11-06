/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:36 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 22:18:05 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf_data(t_fdf *fdf, char *file)
{
	fdf->settings.scale = 30;
	fdf->settings.projections = ISOMETRIC;
	fdf->settings.use_color_scheme = 1;
	fdf->map = NULL;
	fdf->max_height = 0;
	fdf->min_height = 0;
	fdf->data_interface.file_name = file;
}

void	init_fdf(t_fdf *fdf, t_image *image)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fil de Fer");
	image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, 
		&image->line_length, &image->endian);
	fdf->image = image;
	set_interface_data(fdf);
	reset_settings(fdf);
	center_point(fdf);
	create_buton(fdf);
	fdf_rendering(fdf);
	mlx_hook(fdf->mlx_win, 3, (1L<<1), on_keydown, fdf);
	mlx_hook(fdf->mlx_win, 4, (1L<<2), on_mouse_down, fdf);
	mlx_hook(fdf->mlx_win, 17, (0L), on_cross_click, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int argc, char **argv)
{
	t_image				image;
	t_fdf				fdf;

	init_fdf_data(&fdf, argv[1]);
	if (!args_checker(argc, argv))
		return(1);
	if (!parse_map(argv[1], &fdf))
		return (1);
	init_fdf(&fdf, &image);
	exit (0);
}
