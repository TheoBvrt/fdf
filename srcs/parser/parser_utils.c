/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:48:26 by theo              #+#    #+#             */
/*   Updated: 2025/11/07 16:28:01 by thbouver         ###   ########.fr       */
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

int	fill_point(t_fdf *fdf, char *array, int y, int index)
{
	char	**tmp;
	char	*nl;

	tmp = ft_split(array, ',');
	if (!tmp)
		return (0);
	nl = ft_strchr(tmp[1], '\n');
	if (nl)
		*nl = '\0';
	fdf->map[y][index].x = index;
	fdf->map[y][index].y = y;
	fdf->map[y][index].z = (float)ft_atoi(tmp[0]);
	fdf->map[y][index].color = get_color(fdf, tmp[1]);
	free_tab(tmp);
	free (array);
	return (1);
}

int	check_size(char *str)
{
	char	**tmp;
	int		size;

	if (str == NULL)
		return (-1);
	tmp = ft_split(str, ' ');
	if (!tmp)
		return (-1);
	size = get_count_of_array(tmp);
	free_tab(tmp);
	return (size);
}
