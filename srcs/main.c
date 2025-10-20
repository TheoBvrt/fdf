#include "fdf.h"

int	main(void)
{
    int		fd;
	char	*line;

	fd = open("test.c", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		ft_printf("%s", line);
		free (line);
	}
}

/*int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);

	int fd = open("Makefile", O_RDONLY);

	char *line;
	while ((line = get_next_line(fd)))
	{
            printf ("%s", line);
            free (line);
	}
}*/
