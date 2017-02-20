/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:52:57 by itsuman           #+#    #+#             */
/*   Updated: 2016/12/18 21:17:07 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_3(int n)
{
	if (n == 3 || n == 4)
		return (1);
	return (0);
}

int		check_figure(char *s)
{
	int i;
	int j;
	int n;

	i = -1;
	while (s[++i] != '\0')
	{
		j = 0;
		n = 0;
		while (s[i] != '\0' && !(s[i] == '\n' && s[i - 1] == '\n'))
		{
			if (s[i] == '#' && s[i + 1] == '#')
				j++;
			if (n < 3)
				if (s[i] == '#' && s[i + 5] == '#')
					j++;
			if (s[i++] == '\n')
				n++;
		}
		if (check_3(j) == 0)
			return (0);
	}
	return (1);
}

int		check_2(char *s)
{
	int i;
	int n;

	i = 0;
	while (s[i] != '\0')
	{
		n = 0;
		while (s[i] != '\0' && s[i] != '\n')
		{
			n++;
			i++;
		}
		if (s[i] == '\n' && s[i - 1] != '\n')
			if (n != 4)
				return (0);
		i++;
	}
	return (check_figure(s));
}

int		check_1(char *s)
{
	int i;
	int j;
	int t;
	int n;

	i = -1;
	while (s[++i] != '\0')
	{
		j = 0;
		t = 0;
		n = 0;
		while (s[i] != '\0' && !(s[i] == '\n' && s[i - 1] == '\n'))
		{
			if (s[i] == '.')
				n++;
			if (s[i] == '#')
				j++;
			if (s[i] == '\n')
				t++;
			i++;
		}
		if (j != 4 || t != 4 || n != 12)
			return (0);
	}
	return (check_2(s));
}

char	*read_file(int fd)
{
	char	e[BUF_SIZE + 1];
	char	*s;
	int		i;
	int		t;

	t = 1;
	i = 0;
	s = (char *)malloc(550);
	while (t > 0)
	{
		if ((t = read(fd, e, BUF_SIZE)) == -1)
		{
			ft_putstr("error\n");
			exit(1);
		}
		else
			s[i++] = e[0];
	}
	s[i] = '\0';
	if (!(check_1(s)))
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (s);
}
