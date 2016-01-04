/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:34:22 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/23 15:55:02 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	g_ok;
int		g_map[24][24];

void	ft_print_map(int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (g_map[i][j] == 0)
				write(1, ".", 1);
			else
				ft_putchar((char)g_map[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	exit(EXIT_SUCCESS);
}

t_bool	ft_check_piece(int map[][4], int st_i, int st_j, int len)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4 && i + st_i < len)
	{
		j = 0;
		while (j < 4 && j + st_j < len)
		{
			if (g_map[st_i + i][st_j + j] != 0 && map[i][j] != 0)
				return (0);
			if (map[i][j] != 0)
				count++;
			if (count == 4)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_put_piece(t_piece *elem, int st_i, int st_j, char ch)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!elem->map[i][j] == 0)
				g_map[st_i + i][st_j + j] = ch;
			j++;
		}
		i++;
	}
}

void	ft_back(t_piece *v, unsigned idx, unsigned len, unsigned n)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;

	i = -1;
	while (v[idx].seen == 0 && ++i < len)
	{
		j = -1;
		while (++j < len)
			if (ft_check_piece(v[idx].map, i, j, len))
			{
				v[idx].seen = 1;
				ft_put_piece(&v[idx], i, j, idx + 'A');
				if (ft_all_seen(v, n))
					ft_print_map(len);
				else
				{
					k = 0;
					while (k < n)
						ft_back(v, k++, len, n);
				}
				ft_put_piece(&v[idx], i, j, 0);
				v[idx].seen = 0;
			}
	}
}

void	ft_create_map(t_piece *v, unsigned n)
{
	unsigned	side_len;
	unsigned	i;

	side_len = ft_sqrt_ceil(n * 4);
	i = 0;
	while (i < n)
	{
		ft_back(v, i++, side_len, n);
		if (i == n)
		{
			side_len++;
			i = 0;
		}
	}
}
