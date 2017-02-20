/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:55:54 by itsuman           #+#    #+#             */
/*   Updated: 2016/12/20 19:51:57 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fig	write_fig(char *s, t_fig f, int x, int xn)
{
	int	i;
	int	y;
	int	j;

	i = 0;
	y = 0;
	j = 1;
	while (!(s[i] == '\n' && s[i - 1] == '\n') || s[i] == '\0')
	{
		if (s[i] == '\n')
		{
			x = 0;
			y++;
		}
		else if (s[i] == '#')
		{
			f.x[j] = x - xn;
			f.y[j++] = y;
			x++;
		}
		else
			x++;
		i++;
	}
	return (f);
}

t_fig	write_figure(char *s, t_fig f)
{
	int i;
	int j;
	int x;
	int xn;

	i = -1;
	j = 0;
	x = 0;
	xn = 0;
	while (s[++i])
	{
		if (s[i] == '\n')
			x = 0;
		else if (s[i] == '#')
		{
			f.x[j] = 0;
			f.y[j++] = 0;
			xn = x++;
			break ;
		}
		else
			x++;
	}
	return (write_fig(s + ++i, f, x, xn));
}

int		figure_count(char *s)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			j++;
		if (j == 4)
			count++;
		if (j == 5)
			j = 0;
		i++;
	}
	if (count > 26)
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (count);
}

t_fig	**read_figure(char *s)
{
	t_fig	**f;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	f = (t_fig **)malloc(sizeof(t_fig) * figure_count(s) + 1);
	while (s[i] != '\0')
	{
		f[count] = (t_fig *)malloc(sizeof(t_fig));
		*f[count] = write_figure(s + i, *f[count]);
		count++;
		while (!(s[i] == '\n' && s[i - 1] == '\n') || s[i] == '\0')
			i++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	f[count] = NULL;
	return (f);
}
