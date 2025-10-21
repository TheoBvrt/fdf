/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:29 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/21 15:10:15 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_tab(char *tmp, t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	fdf->_heightmap = ft_split(tmp, '\n');
	while (fdf->_heightmap[y])
	{
		x = 0;
		while (fdf->_heightmap[y][x])
		{
			if (!ft_isdigit(fdf->_heightmap[y][x]))
			{
				free_tab(fdf->_heightmap);
				return (1);
			}
			x ++;
		}
		y ++;
	}
	free_tab(fdf->_heightmap);
	
}

int	parse_map(char *file_name, t_fdf *fdf)
{
	char	*line;
	char	*tmp;
	char	**char_tab;
	int		fd;

	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		return (1);
	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_realloc(tmp, line);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	if (!check_tab(tmp, fdf))
	{
		free (tmp);
		return (1);
	}
	free (tmp);
	return (0);
}