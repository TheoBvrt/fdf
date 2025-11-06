/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 15:59:13 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

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

static int get_gradient(int c1, int c2, float t)
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

static void	dda_line(t_fdf *fdf, t_vec2 start, t_vec2 end, int color_start, int color_end)
{
	int color;
	int dx = end.x - start.x;
	int dy = end.y - start.y;

	int steps = abs(dy);

	if ((!(start.x >= 0 && start.x <= WIDTH) || !(start.y >= 0 && start.y <= HEIGHT))
		&& (!(end.x >= 0 && end.x <= WIDTH) || !(end.y >= 0 && end.y <= HEIGHT)))
			return ;	
	if (abs(dx) > abs(dy))
		steps = abs(dx);

	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = start.x;
	float Y = start.y;
	int index = 0;
	while (index <= steps)
	{
		if (color_start == color_end)
			color = color_start;
		else
			color = get_gradient(color_end, color_start, (float)index / steps);
		my_mlx_put_pixel(fdf->image, X, Y, color);
		X += Xinc;
		Y += Yinc;
		index ++;
	}
}

static void	clear_screen(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	mlx_destroy_image(fdf->mlx, fdf->image->img);
	fdf->image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->image->addr = mlx_get_data_addr(fdf->image->img,
		&fdf->image->bits_per_pixel, &fdf->image->line_length, &fdf->image->endian);
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			my_mlx_put_pixel(fdf->image, x, y, PROJECTION_BACKGROUND);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
}

void	fdf_rendering(t_fdf *fdf)
{
	t_vec2	start_pos;
	t_vec3	tmp;
	int		y;
	int		x;

	y = 0;
	clear_screen(fdf);
	while (y < fdf->map_height)
	{
		x = 0;
		while (x < fdf->map_width)
		{
			tmp = fdf->map[y][x];
			start_pos = projection(tmp, fdf, (int []){y, x});
			if (x - 1 >= 0)
				dda_line(fdf, start_pos, projection(fdf->map[y][x - 1],
						fdf, (int []){y, x - 1}), fdf->map[y][x - 1].color, tmp.color);
			if (y - 1 >= 0)
				dda_line(fdf, start_pos, projection(fdf->map[y - 1][x],
						fdf, (int []){y - 1, x}), fdf->map[y - 1][x].color, tmp.color);
			x ++;
		}
		y ++;
	}
	draw_interface(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image->img, 0, 0);
	mlx_set_font(fdf->mlx, fdf->mlx_win, TITLE_FONT);
	put_string(fdf);
}
