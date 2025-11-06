/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:55:57 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 21:46:05 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	on_click(t_fdf *fdf, int projection)
{
	fdf->settings.projections = projection;
}

static t_button	*new_button(int colors[2], t_vec2 start, int size[], int proj)
{
	t_button	*new;

	new = malloc (1 * sizeof(t_button));
	if (!new)
		return (NULL);
	new->color = colors[0];
	new->accent_color = colors[1];
	new->start = start;
	new->width = size[0];
	new->height = size[1];
	new->projection = proj;
	new->enable = 0;
	return (new);
}

void	create_buton(t_fdf *fdf)
{
	fdf->data_interface.button[0]
		= new_button((int []){BUTTON_BACKGROUND, ACCENT_COLOR},
			(t_vec2){TITLE_X, HEIGHT * 0.45}, (int []){WIDTH * 0.085,
			HEIGHT * 0.05}, SPHERIC);
	fdf->data_interface.button[1]
		= new_button((int []){BUTTON_BACKGROUND, ACCENT_COLOR},
			(t_vec2){TITLE_X + WIDTH * 0.09, HEIGHT * 0.45},
			(int []){WIDTH * 0.085, HEIGHT * 0.05}, ORTHOGRAPHIC);
	fdf->data_interface.button[2]
		= new_button((int []){BUTTON_BACKGROUND, ACCENT_COLOR},
			(t_vec2){TITLE_X, HEIGHT * 0.509},
			(int []){WIDTH * 0.175, HEIGHT * 0.05}, ISOMETRIC);
	fdf->data_interface.button[2]->enable = 1;
}

void	find_button(t_fdf *fdf, int x, int y)
{
	t_button	*btn;
	int			index;

	index = 0;
	while (index < 3)
	{
		btn = fdf->data_interface.button[index];
		if (x >= btn->start.x && x <= (btn->start.x + btn->width)
			&& y >= btn->start.y && y <= (btn->start.y + btn->height))
		{
			on_click(fdf, btn->projection);
			fdf->data_interface.button[0]->enable = 0;
			fdf->data_interface.button[1]->enable = 0;
			fdf->data_interface.button[2]->enable = 0;
			btn->enable = 1;
			return ;
		}
		index ++;
	}
}

void	display_button(t_fdf *fdf)
{
	t_button	*tmp;
	int			index;

	index = 0;
	while (index < 3)
	{
		tmp = fdf->data_interface.button[index];
		draw_rectangle(fdf, tmp->start,
			(int []){tmp->width, tmp->height}, tmp->color);
		if (tmp->enable == 1)
			draw_rectangle(fdf, (t_vec2){tmp->start.x, tmp->start.y
				+ tmp->height - HEIGHT * 0.01},
				(int []){tmp->width, HEIGHT * 0.01}, tmp->accent_color);
		index ++;
	}
}
