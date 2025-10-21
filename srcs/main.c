/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:36 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/21 14:50:01 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf fdf;

	if (!args_checker(argc, argv))
		return(1);
	if (!parse_map(argv[1], &fdf))
		return (1);
	exit (0);
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
