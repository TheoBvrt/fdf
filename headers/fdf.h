/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:41:21 by theo              #+#    #+#             */
/*   Updated: 2025/11/07 16:26:45 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "math.h"
# include "stdio.h"

# ifndef KEYCODE
#  define ESCAPE 65307
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 3
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define A_KEY 97
#  define D_KEY 100
#  define W_KEY 119
#  define S_KEY 115
#  define R_KEY 114
#  define MINUS_KEY 45
#  define PLUS_KEY 61
# endif

# ifndef CONSTANT
#  define WIDTH 2560
#  define HEIGHT 1440
#  define ANGLE 0.523599
#  define ISOMETRIC 1
#  define ORTHOGRAPHIC 2
#  define SPHERIC 3
# endif

# ifndef COLOR
#  define DEFAULT_COLOR 0x2e808a
#  define DEFAULT_START_COLOR 0x2e808a
#  define DEFAULT_END_COLOR 0xff7b00
#  define PROJECTION_BACKGROUND 0x151515
#  define INTERFACE_BACKGROUND 0x202020
#  define MAIN_COLOR 0xf2f0f0
#  define ACCENT_COLOR 0xfc9803
#  define BUTTON_BACKGROUND 0x302f2f
# endif

# ifndef FONT
#  define TF "-misc-fixed-medium-r-normal--24-230-75-75-c-120-iso8859-1"
# endif

typedef struct vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct vec3
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_vec3;

typedef struct rgb_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb_color;

typedef struct button
{
	int		color;
	int		accent_color;
	t_vec2	start;
	int		width;
	int		height;
	int		enable;
	int		projection;
}	t_button;

typedef struct data_interface
{
	t_button	*button[3];
	char		*file_name;
	char		*map_size;
	char		*offsets;
	char		*height_scale;
	char		*scale;
	char		*angle;
}	t_data_interface;

typedef struct image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct render_settings
{
	int		scale;
	int		offset_x;
	int		offset_y;
	int		roll;
	int		pitch;
	int		yaw;
	int		projections;
	int		use_color_scheme;
	float	height;
}	t_render_settings;

typedef struct dda
{
	int		color;
	int		dx;
	int		dy;
	int		s;
	int		i;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
}	t_dda;

typedef struct rendering
{
	int		y;
	int		x;
	t_vec2	start;
	t_vec3	tmp;
}	t_rendering;

typedef struct fdf
{
	t_vec3				**map;
	t_image				*image;
	t_render_settings	settings;
	t_data_interface	data_interface;
	void				*mlx;
	void				*mlx_win;
	int					map_height;
	int					map_width;
	int					min_height;
	int					max_height;
}	t_fdf;

// parsing
void	create_color_scheme(t_fdf *fdf);
void	set_interface_data(t_fdf *fdf);
void	update_interface_data(t_fdf *fdf);
char	*format_offsets(int offset_x, int offset_y);
int		parse_map(char *file_name, t_fdf *fdf);
int		args_checker(int argc, char **argv);
int		get_gradient(int c1, int c2, float t);
int		get_color(t_fdf *fdf, char *str);
int		get_count_of_array(char **array);
int		fill_point(t_fdf *fdf, char *array, int y, int index);
int		check_size(char *str);

// rendering
t_vec3	rotate_x(t_vec3 point, float angle);
t_vec3	rotate_y(t_vec3 point, float angle);
t_vec3	rotate_z(t_vec3 point, float angle);
t_vec2	projection(t_vec3 vec3, t_fdf *fdf, int index[2]);
void	my_mlx_put_pixel(t_image *image, int x, int y, int color);
void	fdf_rendering(t_fdf *fdf);
void	reset_settings(t_fdf *fdf);
void	draw_interface(t_fdf *fdf);
void	create_buton(t_fdf *fdf);
void	draw_rectangle(t_fdf *fdf, t_vec2 start, int size[2], int color);
void	display_button(t_fdf *fdf);
void	find_button(t_fdf *fdf, int x, int y);
void	put_string_infos(t_fdf *fdf);
void	put_string_transformations(t_fdf *fdf);
void	put_string_projections(t_fdf *fdf);
void	put_string_control(t_fdf *fdf);
void	put_string(t_fdf *fdf);
int		on_keydown(int keycode, t_fdf *fdf);
int		on_mouse_down(int keycode, int x, int y, t_fdf *fdf);
int		on_cross_click(t_fdf *fdf);

// utils
void	print_line_len_error(int size);
void	free_tab(char **tab);
void	free_vec3_tab(t_vec3 **tab, int size);
void	clean_program(t_fdf *fdf);
void	center_point(t_fdf *fdf);
float	deg_to_radian(float x);

#endif