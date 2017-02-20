/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:12:27 by itsuman           #+#    #+#             */
/*   Updated: 2016/12/23 17:26:42 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_space(char **map, t_fig *f, int size, int *xy)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (xy[0] + f->y[i] >= size)
			return (0);
		if (xy[1] + f->x[i] >= size)
			return (0);
		if (map[xy[0] + f->y[i]][xy[1] + f->x[i]] != '.')
			return (0);
		i++;
	}
	f->xx = xy[1];
	f->yy = xy[0];
	return (1);
}

void	fig_write(t_fig *f, char **map, char ch)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[f->yy + f->y[i]][f->xx + f->x[i]] = ch;
		i++;
	}
}

void	map_free(char **map)
{
	if (map != NULL)
	{
		free(*map);
		*map = NULL;
	}
}

int		fill_map(t_fig **f, char **map, int i, int size)
{
	int xy[2];

	if (f[i] == NULL)
		return (1);
	xy[0] = -1;
	while (++xy[0] < size)
	{
		xy[1] = -1;
		while (++xy[1] < size)
		{
			while (free_space(map, f[i], size, xy))
			{
				fig_write(f[i], map, 'A' + i);
				if (fill_map(f, map, i + 1, size))
					return (1);
				else
				{
					fig_write(f[i], map, '.');
					xy[1]++;
				}
			}
		}
	}
	return (0);
}
