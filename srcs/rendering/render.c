/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:34 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/21 17:32:46 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void    dda_line(t_fdf *fdf, t_pos start_pos, t_pos end_pos)
{
	int	draw_x;
	int	draw_y;
	int	steps;

	draw_x = start_pos.x - end_pos.x;
	draw_x = start_pos.y - end_pos.y;
	
}

void fdf_rendering(t_fdf *fdf)
{
	t_pos	start;
	t_pos	end;

	start.x = 0;
	start.y = 0;

	end.x = 0;
	end.y = 0;
	
	dda_line(fdf, start, end);
}