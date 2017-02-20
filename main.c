/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:26:37 by itsuman           #+#    #+#             */
/*   Updated: 2016/12/23 16:47:24 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	*buf;
	t_fig	**figs;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	if ((buf = read_file(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	figs = read_figure(buf);
	write_map(figs);
	return (0);
}
