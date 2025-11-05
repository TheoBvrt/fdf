/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:21:09 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/05 18:13:02 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_inbase(char c)
{
	char	*cbase;
	char	*mbase;
	int		index;

	cbase = "0123456789ABCDEF";
	mbase = "0123456789abcdef";
	index = 0;
	while (index < 16)
	{
		if (c == cbase[index] || c == mbase[index])
			return (1);
		index ++;
	}
	return (0);
}

static int	ahtoi(char *str)
{
	int	index;
	int	res;

	index = 2;
	res = 0;
	if (str[0] != '0' && str[1] != 'x')
		return (-1);
	while (str[index])
	{
		res *= 16;
		if (!is_inbase(str[index]))
			return (-1);
		if (str[index] >= '0' && str[index] <= '9')
			res += str[index] - '0';
		else if (str[index] >= 'a' && str[index] <= 'f')
			res += str[index] - 'a' + 10;
		else if (str[index] >= 'A' && str[index] <= 'F')
			res += str[index] - 'A' + 10;
		index ++;
	}
	return (res);
}

int	get_color(char *str)
{
	int	color;

	if (str)
	{
		color = ahtoi(str);
		if (color == -1)
			return (DEFAULT_COLOR);
	}
	else
		color = DEFAULT_COLOR;
	return (color);
}
