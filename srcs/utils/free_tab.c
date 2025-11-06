/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:40:59 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/06 22:43:39 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		free (tab[index]);
		index ++;
	}
	free (tab);
}

void	free_vec3_tab(t_vec3 **tab, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		free (tab[index]);
		index ++;
	}
	free (tab);
}
