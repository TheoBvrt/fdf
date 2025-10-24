/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:40:59 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/24 17:04:54 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

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