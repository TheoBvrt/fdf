/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:29 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/07 00:00:30 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fill_line(t_fdf *fdf, char **array, int y)
{
	int		i;

	i = get_count_of_array(array);
	fdf->map[y] = (t_vec3 *)malloc (sizeof(t_vec3) * i);
	if (!fdf->map[y])
		return (0);
	if (y == 0)
		fdf->map_width = i;
	i = 0;
	while (array[i])
	{
		fill_point(fdf, array[i], y, i);
		i ++;
	}
	free (array);
	return (1);
}

static int	create_vec3_tab(t_fdf *fdf, char *file_name)
{
	char	**array;
	char	*line;
	int		fd;
	int		index;

	index = 0;
	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		array = ft_split(line, ' ');
		if (!array)
			return (0);
		free (line);
		if (!fill_line(fdf, array, index++))
			return (close (fd), 0);
		line = get_next_line(fd);
	}
	free (line);
	return (close(fd), 1);
}

static int	get_height_size(char *file_name)
{
	char	*line;
	int		size;
	int		fd;

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		size ++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	return (close(fd), size);
}

int	parse_map(char *file_name, t_fdf *fdf)
{
	int	size;

	size = get_height_size(file_name);
	if (size <= 0)
		return (0);
	fdf->map = (t_vec3 **)malloc(sizeof(t_vec3 *) * size);
	if (!fdf->map)
		return (0);
	fdf->map_height = size;
	if (!create_vec3_tab(fdf, file_name))
	{
		free_vec3_tab(fdf->map, fdf->map_height);
		return (1);
	}
	if (fdf->settings.use_color_scheme == 1)
		create_color_scheme(fdf);
	return (1);
}
