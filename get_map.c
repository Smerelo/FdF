/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:18:35 by smerelo           #+#    #+#             */
/*   Updated: 2018/04/03 21:38:02 by smerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_map(int fd)
{
	char	*map;
	char	*buff;
	int		i;
	char	**map2;

	i = 0;
	map = ft_strnew(1);
	while (get_next_line(fd, &buff) > 0)
	{
		map = ft_strjoin2(map, buff);
		ft_strdel(&buff);
	}
	while (map[i])
	{
		if ((map[i] < '0' || map[i] > '9') && map[i] != ' '
			&& map[i] != '-' && map[i] != '+')
			return (NULL);
		i++;
	}
	if ((map2 = ft_strsplit(map, ' ')) == NULL)
		return (0);
	i = -1;
	ft_strdel(&map);
	return (map2[0] == NULL ? NULL : map2);
}
