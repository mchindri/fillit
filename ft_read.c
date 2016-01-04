/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:54:30 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/30 14:36:58 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_read_element(int fd, t_piece *elem)
{
	char	buf[6];
	int		i;
	int		j;
	int		ok;

	i = 0;
	while (i < 4)
	{
		ok = read(fd, buf, 5);
		if (ok != 5 || ft_strchr(buf, '\n') - buf != 4)
			return (0);
		j = 0;
		while (j < 4)
		{
			if (buf[j] != '.' && buf[j] != '#')
				return (0);
			else if (buf[j] == '.')
				elem->map[i][j] = 0;
			else
				elem->map[i][j] = 1;
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_read(int fd, t_piece vect[])
{
	int		i;
	int		ok;
	int		ok2;
	char	aux[2];

	i = 0;
	ok = ft_read_element(fd, vect + i);
	while (ok == 1)
	{
		vect[i].seen = 0;
		if (!ft_check_map(vect + i))
			return (-1);
		ok2 = read(fd, aux, 1);
		i++;
		ok = ft_read_element(fd, vect + i);
		if (ok2 && ok == 0)
			return (-1);
	}
	if (i > 26 || i == 0)
		return (-1);
	else
		return (i);
}
