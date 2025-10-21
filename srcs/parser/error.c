/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:24 by thbouver          #+#    #+#             */
/*   Updated: 2025/10/21 14:47:54 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int extension_checker(char *file_name, char *extension)
{
	int index;

	index = ft_strlen(file_name) - ft_strlen(extension);
	if (index < 0)
	{
		ft_printf("[erreur] : merci de selectionner un fichier .fdf");
		return (1);
	}
	while (file_name[index] && *extension)
	{
		if (file_name[index] != *extension)
		{
			ft_printf("[erreur] : merci de selectionner un fichier .fdf");
			return (1);
		}
		index ++;
		extension ++;
	}
	return (0);
}

int	args_checker(int argc, char **argv)
{
	int	file;

	if (argc != 2)
	{
		ft_printf("[erreur] : arguments invalide ./fdf <file>\n");
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_printf("[erreur] : impossible d'ouvrir le fichier\n");
		return (1);
	}
	close (file);
	if (!extension_checker(argv[1], ".fdf"))	
		return (1);
    return (0);
}