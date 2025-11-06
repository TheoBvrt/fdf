/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:48:26 by theo              #+#    #+#             */
/*   Updated: 2025/11/06 22:55:15 by theo             ###   ########.fr       */
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
