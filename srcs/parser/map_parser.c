/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:29 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/28 11:35:34 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_count_of_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count ++;
	return (count);
}

int	fill_line(t_fdf *fdf, char **array, int y)
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
		fdf->map[y][i].x = i;
		fdf->map[y][i].y = y;
		fdf->map[y][i].z = (float)ft_atoi(array[i]);
		free (array[i]);
		i ++;
	}
	free (array);
	return (1);
}

int	create_vec3_tab(t_fdf *fdf, char *file_name)
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
		if (!fill_line(fdf, array, index))
		{
			close (fd);
			line = get_next_line(fd);
			return (0);
		}
		line = get_next_line(fd);
		index ++;
	}
	free (line);
	close (fd);
	return (1);
}

int	get_height_size(char *file_name)
{
	char *line;
	int	size;
	int	fd;
	
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
	close (fd);
	return (size);
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
	return (1);
}
