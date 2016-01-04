/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:49:05 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/23 19:41:08 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_piece
{
	int map[4][4];
	int seen;
}				t_piece;

int				ft_read(int fd, t_piece vect[]);
int				ft_check_map(t_piece *elem);
void			ft_create_map(t_piece *v, unsigned n);
int				ft_sqrt_ceil(int n);
t_bool			ft_all_seen(t_piece *v, int n);
char			*ft_strchr(const char *s, int c);
void			ft_putchar(char c);

#endif
