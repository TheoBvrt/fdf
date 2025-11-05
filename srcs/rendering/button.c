/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:55:57 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/05 16:04:40 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_button	*new_button(int colors[2], t_vec2 vec2[2], void (*f)(t_fdf *fdf))
{
	t_button	*new;

	new = malloc (1 * sizeof(t_button));
	if (!new)
		return (NULL);
	new->accent_color = colors[0];
	new->accent_color = colors[1];
	new->start = vec2[0];
	new->width = vec2[1].x;
	new->width = vec2[1].y;
	new->on_click = f;
	return (new_button);
}

void	display_button(t_fdf *fdf)
{
	t_button	tmp;
	int			index;

	index = 0;
	while (index < 3)
	{
		tmp = fdf->data_interface.button[index];
		
		index ++;
	}
}