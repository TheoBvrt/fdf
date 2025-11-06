/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:02:39 by theo              #+#    #+#             */
/*   Updated: 2025/11/06 21:45:52 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*concat_float_part(char *integer, char *decimal, int negative)
{
	char	*str;
	size_t	size;

	size = ft_strlen(integer) + ft_strlen(decimal) + 2;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	if (negative == 1)
		ft_strlcat(str, "-", size);
	ft_strlcat(str, integer, size);
	ft_strlcat(str, ".", size);
	ft_strlcat(str, decimal, size);
	return (str);
}

static char	*ft_ftoa(float number)
{
	char	*str;
	char	*integer;
	char	*decimal;
	int		negative;

	negative = 0;
	if (number < 0 && number > -1.0)
		negative = 1;
	integer = ft_itoa((int)number);
	if (!integer)
		return (NULL);
	decimal = ft_itoa((int)roundf(fabsf(number - (int)number) * 100));
	if (!decimal)
	{
		free (integer);
		return (NULL);
	}
	str = concat_float_part(integer, decimal, negative);
	free (integer);
	free (decimal);
	return (str);
}

static char	*concat_angle(char *roll, char *pitch, char *yaw)
{
	char	*str;
	size_t	size;

	size = ft_strlen(roll) + ft_strlen(pitch) + ft_strlen(yaw) + 9;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, "X:", size);
	ft_strlcat(str, roll, size);
	ft_strlcat(str, " Y:", size);
	ft_strlcat(str, pitch, size);
	ft_strlcat(str, " Z:", size);
	ft_strlcat(str, yaw, size);
	return (str);
}

static char	*format_angle(int roll, int pitch, int yaw)
{
	char	*str;
	char	*str_roll;
	char	*str_pitch;
	char	*str_yaw;

	str_roll = ft_itoa(roll);
	if (!str_roll)
		return (NULL);
	str_pitch = ft_itoa(pitch);
	if (!str_pitch)
		return (NULL);
	str_yaw = ft_itoa(yaw);
	if (!str_yaw)
		return (NULL);
	str = concat_angle(str_roll, str_pitch, str_yaw);
	free (str_roll);
	free (str_pitch);
	free (str_yaw);
	return (str);
}

void	update_interface_data(t_fdf *fdf)
{
	char	*tmp;

	tmp = ft_itoa(fdf->settings.scale);
	free (fdf->data_interface.angle);
	free (fdf->data_interface.height_scale);
	free (fdf->data_interface.scale);
	free (fdf->data_interface.offsets);
	fdf->data_interface.angle = format_angle(fdf->settings.roll,
			fdf->settings.pitch, fdf->settings.yaw);
	fdf->data_interface.height_scale = ft_ftoa(fdf->settings.height);
	fdf->data_interface.scale = ft_strjoin("x", tmp);
	fdf->data_interface.offsets = format_offsets(fdf->settings.offset_x,
			fdf->settings.offset_y);
	free (tmp);
}
