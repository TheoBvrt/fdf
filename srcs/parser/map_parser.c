/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:29 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/24 14:44:06 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_line(t_vec3 **vec3_tab, char **array, int vec3_tab_index)
{
	int	index;

	index = 0;
	while (array[index])
	{
		ft_printf ("%s\n", array[index]);
		free (array[index]);
		index ++;
	}
	free (array);
}

int	create_vec3_tab(t_vec3 **vec3_tab, char *file_name)
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
		fill_line(vec3_tab, array, index);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (0);
}

int	get_height_size(char *file_name)
{
	char *line;
	int	size;
	int	fd;
	
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
	// fdf->map = (t_vec3 **)malloc(sizeof(t_vec3 *) * size);
	// if (!fdf->map)
	// 	return (1);
	if (!create_vec3_tab(fdf->map, file_name))
		return (1);	
	return (0);
}
