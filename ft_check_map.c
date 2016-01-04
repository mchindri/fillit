/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 19:26:21 by mchindri          #+#    #+#             */
/*   Updated: 2015/12/30 14:16:35 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_min_i;
int g_min_j;

static int	ft_set_map(t_piece *elem)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_min_i + i < 4 && g_min_j + j < 4)
				elem->map[i][j] = elem->map[i + g_min_i][j + g_min_j];
			else
				elem->map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_count_block(int i, int j, t_piece *elem, char dir)
{
	int n;

	if (elem->map[i][j] == -1 || elem->map[i][j] == 0)
		return (0);
	if (i < g_min_i)
		g_min_i = i;
	if (j < g_min_j)
		g_min_j = j;
	elem->map[i][j] = -1;
	n = 1;
	if (dir != 'u' && i > 0)
		n += ft_count_block(i - 1, j, elem, 'd');
	if (dir != 'd' && i < 3)
		n += ft_count_block(i + 1, j, elem, 'u');
	if (dir != 'l' && j > 0)
		n += ft_count_block(i, j - 1, elem, 'r');
	if (dir != 'r' && j < 3)
		n += ft_count_block(i, j + 1, elem, 'l');
	return (n);
}

int			ft_check_map(t_piece *elem)
{
	int ok;
	int i;
	int j;

	ok = 0;
	i = -1;
	g_min_i = 4;
	g_min_j = 4;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (elem->map[i][j] == 1)
			{
				if (ok == 0 && ft_count_block(i, j, elem, 'c') == 4)
					ok = 1;
				else
					return (0);
			}
	}
	if (ok == 1)
		return (ft_set_map(elem));
	return (0);
}
