/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:03:24 by thbouver          #+#    #+#             */
/*   Updated: 2025/11/07 16:35:45 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	extension_checker(char *file_name, char *extension)
{
	int	index;

	index = ft_strlen(file_name) - ft_strlen(extension);
	if (index < 0)
	{
		ft_putstr_fd("[erreur] : merci de selectionner un fichier .fdf", 2);
		return (1);
	}
	while (file_name[index] && *extension)
	{
		if (file_name[index] != *extension)
		{
			ft_putstr_fd("[erreur] : merci de selectionner un fichier .fdf", 2);
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
		ft_putstr_fd("[erreur] : arguments invalide ./fdf <file>\n", 2);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_putstr_fd("[erreur] : impossible d'ouvrir le fichier\n", 2);
		return (1);
	}
	close (file);
	if (!extension_checker(argv[1], ".fdf"))
		return (1);
	return (0);
}

void	print_line_len_error(int size)
{
	if (size == -1)
		ft_putstr_fd("[erreur] : nombre de ligne invalide\n", 2);
}
