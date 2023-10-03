/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:29:19 by ricardo           #+#    #+#             */
/*   Updated: 2023/10/03 19:33:55 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_caracteres_valids(char *s)
{
	char	*map;
	int		i;
	int		count;

	i = 0;
	count = 0;
	map = "PEC01\n";
	while (s[count] != '\0')
	{
		if (s[count] == map[i])
		{
			count++;
			i = 0;
		}
		else if (i == 6)
			return (0);
		else if (s[count] != map[i])
			i++;
	}
	return (1);
}

char	**save_map(char **map, int fd)
{
	static int	i;
	char		*lines_map;

	lines_map = get_next_line(fd);
	if (lines_map)
	{
		i++;
		map = save_map(map, fd);
	}
	if (!map && i != 0)
		map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		exit(ft_putstr_fd("Erro, o mapa é falso\n", 1));
	map[i--] = lines_map;
	return (map);
}
