#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "math.h"
# include "stdio.h"

# define DEG_TO_RADIAN(x) ((x) * M_PI / 180)
# define DEFAULT_COLOR 0x2e808a
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define A_KEY 97
# define D_KEY 100
# define W_KEY 119
# define S_KEY 115


# define WIDTH 3880
# define HEIGHT 2160
# define ANGLE 0.523599


typedef struct image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct vec2 {
	float	x;
	float	y;
}	t_vec2;

typedef struct vec3 {
	float	x;
	float	y;
	float	z;
	int		color;
}	t_vec3;

typedef struct render_settings {
	int	scale;
	int	offset_x;
	int	offset_y;
}	t_render_settings;

typedef struct fdf {
	t_vec3				**map;
	t_image				*image;
	t_render_settings	*settings;
	void				*mlx;
	void				*mlx_win;
	int					map_height;
	int					map_width;
	int					win_width;
	int					win_height;
}	t_fdf;

// parsing
int	parse_map(char *file_name, t_fdf *fdf);
int	args_checker(int argc, char **argv);
int ahtoi(char *str);
int	get_color(char *str);

// rendering
t_vec3	rotate_x(t_vec3 point, float angle);
t_vec3	rotate_y(t_vec3 point, float angle);
t_vec3	rotate_z(t_vec3 point, float angle);
t_vec3 **rotate_matrix(t_vec3 **vec3_tab, t_fdf *fdf, float angle, t_vec3 (*f)(t_vec3, float));
void	my_mlx_put_pixel(t_image *image, int x, int y, int color);
void	fdf_rendering(t_fdf *fdf);
int		on_keydown(int keycode, t_fdf *fdf);
int		on_mouseDown(int keycode, int x, int y, t_fdf *fdf);

// utils
void	free_tab(char **tab);
void	free_vec3_tab(t_vec3 **tab, int size);

#endif