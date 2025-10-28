/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:36 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/28 17:30:48 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_point(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			fdf->map[y][x].y -= (fdf->map_height - 1) / 2;
			fdf->map[y][x].x -= (fdf->map_width - 1) / 2;
			x ++;
		}
		y ++;
	}
}

int	main(int argc, char **argv)
{
	t_image				image;
	t_fdf				fdf;
	t_render_settings	render_settings;

	render_settings.scale = 30;
	fdf.win_width = WIDTH;
	fdf.win_height = HEIGHT;;
	fdf.map = NULL;
	if (!args_checker(argc, argv))
		return(1);
	if (!parse_map(argv[1], &fdf))
		return (1);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, fdf.win_width, fdf.win_height, "FdF");
	image.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, 
		&image.line_length, &image.endian);
	
	render_settings.offset_x = (WIDTH / 2);
	render_settings.offset_y = (HEIGHT / 2);

	fdf.settings = &render_settings;
	fdf.image = &image;
	center_point(&fdf);

	fdf_rendering(&fdf);
	
	mlx_hook(fdf.mlx_win, 2, (1L<<0), on_keydown, &fdf);
	mlx_hook(fdf.mlx_win, 4, (1L<<2), on_mouseDown, &fdf);
	
	mlx_loop(fdf.mlx);
	//free_vec3_tab(fdf.map, fdf.map_height);
	exit (0);
}