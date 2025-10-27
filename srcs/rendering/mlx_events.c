/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:46:15 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/27 11:43:35 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_keydown(int keycode, t_fdf *fdf)
{
	if (keycode == UP_ARROW)
		ft_printf("ARROW_UP");
	if (keycode == DOWN_ARROW)
		ft_printf("DOWN_ARROW");
	if (keycode == LEFT_ARROW)
		ft_printf("LEFT_ARROW");
	if (keycode == RIGHT_ARROW)
		ft_printf("RIGHT_ARROW");
	return (1);
}

int	on_mouseDown(int keycode, int x, int y, t_fdf *fdf)
{
	if (keycode == SCROLL_UP)
		ft_printf ("SCROLL_UP");
	if (keycode == SCROLL_DOWN)
		ft_printf ("SCROLL_DOWN");
	return (1);
}
