#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "math.h"

typedef struct image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_image;

typedef struct fdf {
	void	*mlx;
	void	*mlx_win;
	t_image	*image;
	char	**_heightmap;
} t_fdf;

typedef struct pos {
	float	y;
	float	x;
} t_pos;

// parsing
int	parse_map(char *file_name, t_fdf *fdf);
int	args_checker(int argc, char **argv);

// rendering
void	my_mlx_put_pixel(t_image *image, int x, int y, int color);
void	fdf_rendering(t_fdf *fdf);

// utils
void	free_tab(char **tab);

#endif