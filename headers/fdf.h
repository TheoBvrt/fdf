#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "math.h"
# include "stdio.h"

# define DEG_TO_RADIAN(x) ((x) * M_PI / 180)
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW 65362
# define DOWN_ARROW 65364


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
}	t_vec3;

typedef struct fdf {
	t_vec3	**map;
	int		map_height;
	int		map_width;
	void	*mlx;
	void	*mlx_win;
	t_image	*image;
	char	**_heightmap;
	int		win_width;
	int		win_height;
}	t_fdf;

// parsing
int	parse_map(char *file_name, t_fdf *fdf);
int	args_checker(int argc, char **argv);

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