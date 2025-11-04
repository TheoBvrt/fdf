/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:13:23 by theo              #+#    #+#             */
/*   Updated: 2025/11/04 23:37:03 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*format_file_name(char *file_name)
{
	int	index;

	index = 0;
	while (file_name[index])
	{
		file_name[index] = ft_toupper(file_name[index]);
		index ++;
	}
	return (file_name);
}

static char	*concat_size(char *map_height, char *map_width)
{
	char	*str;
	size_t	size;

	size = ft_strlen(map_height) + ft_strlen(map_width) + 6;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, "h:", size);
	ft_strlcat(str, map_height, size);
	ft_strlcat(str, " w:", size);
	ft_strlcat(str, map_width, size);
	return (str);
}

static char	*format_map_size(int map_height, int map_width)
{
	char	*str;
	char	*map_h;
	char	*map_w;

	map_h = ft_itoa(map_height);
	if (!map_h)
		return (NULL);
	map_w = ft_itoa(map_width);
	if (!map_w)
	{
		free (map_h);
		return (NULL);
	}
	str = concat_size(map_h, map_w);
	free (map_h);
	free (map_w);
	return (str);
}

void	set_interface_data(t_fdf *fdf)
{
	fdf->data_interface.file_name = format_file_name(fdf->data_interface.file_name);
	fdf->data_interface.map_size = format_map_size(fdf->map_height, fdf->map_width);
	fdf->data_interface.angle = NULL;
}