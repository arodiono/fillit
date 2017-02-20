/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:03:40 by itsuman           #+#    #+#             */
/*   Updated: 2016/12/22 21:13:40 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_fig
{
	int				x[4];
	int				y[4];
	int				xx;
	int				yy;
}					t_fig;

char				*read_file(int fd);
t_fig				**read_figure(char *s);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memset(void *dest, int val, size_t num);
void				write_map(t_fig **f);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
int					fill_map(t_fig **f, char **map, int i, int size);
void				print_map(char **map, int size);
void				map_free(char **map);
int					high_sqrt(int n);
int					count_fig(t_fig **f);

#endif
