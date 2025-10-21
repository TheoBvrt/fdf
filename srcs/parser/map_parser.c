/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:29 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/21 15:43:55 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_tab(char *tmp, t_fdf *fdf)
{
	int	check_len;
	int	y;
	int	x;

	y = 0;
	fdf->_heightmap = ft_split(tmp, '\n');
	check_len = ft_strlen(fdf->_heightmap[0]);
	while (fdf->_heightmap[y])
	{
		x = 0;
		if (ft_strlen(fdf->_heightmap[y]) != check_len)
		{
			free_tab(fdf->_heightmap);
			ft_putstr_fd("[erreur] : la map doit etre rectangulaire", 0);
			return (1);
		}
		while (fdf->_heightmap[y][x])
		{
			if (!ft_isdigit(fdf->_heightmap[y][x]))
			{
				free_tab(fdf->_heightmap);
				ft_putstr_fd("[erreur] : une map ne peux pas contenir autre choses que des chiffres", 0);
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
