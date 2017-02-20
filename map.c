/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 19:39:20 by itsuman           #+#    #+#             */
/*   Updated: 2016/12/23 16:48:10 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int		count_fig(t_fig **f)
{
	int i;

	i = 0;
	while (f[i] != NULL)
		i++;
	return (i);
}

char	**create_map(int size)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * size);
	i = size;
	map[i] = NULL;
	while (i--)
	{
		map[i] = (char *)malloc(sizeof(char) * size);
		map[i] = ft_memset(map[i], 46, size);
	}
	return (map);
}

void	print_map(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	write_map(t_fig **f)
{
	char	**map;
	int		size;

	size = high_sqrt(count_fig(f) * 4);
	map = create_map(size);
	while (!(fill_map(f, map, 0, size)))
	{
		size++;
		map_free(map);
		map = create_map(size);
	}
	print_map(map, size);
}
