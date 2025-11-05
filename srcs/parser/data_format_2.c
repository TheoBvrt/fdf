/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_format_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:03:49 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/05 15:46:37 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*str_concat_offsets(char *offset_x, char *offset_y)
{
	char	*str;
	size_t	size;

	size = ft_strlen(offset_x) + ft_strlen(offset_y) + 6;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, "X:", size);
	ft_strlcat(str, offset_x, size);
	ft_strlcat(str, " Y:", size);
	ft_strlcat(str, offset_y, size);
	return (str);
}

char	*format_offsets(int offset_x, int offset_y)
{
	char	*str;
	char	*off_x;
	char	*off_y;

	off_x = ft_itoa(offset_x - WIDTH / 1.6);
	if (!off_x)
		return (NULL);
	off_y = ft_itoa(offset_y - HEIGHT / 2);
	if (!off_y)
	{
		free (off_x);
		return (NULL);
	}
	str = str_concat_offsets(off_x, off_y);
	free (off_x);
	free (off_y);
	return (str);
}
