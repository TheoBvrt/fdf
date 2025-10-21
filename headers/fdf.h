#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "stdio.h"

typedef struct fdf {
	char	**_heightmap;
} t_fdf;

int	args_checker(int argc, char **argv);

// parsing
int	parse_map(char *file_name, t_fdf *fdf);

// utils
void	free_tab(char **tab);

#endif