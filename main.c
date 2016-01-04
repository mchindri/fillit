/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acioalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:30:01 by acioalai          #+#    #+#             */
/*   Updated: 2016/01/04 15:06:37 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt_ceil(int n)
{
	int i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	if (i * i == n)
		return (i);
	return (i + 1);
}

t_bool		ft_all_seen(t_piece *v, int n)
{
	int i;

	i = 0;
	while (i < n)
		if (v[i++].seen == 0)
			return (0);
	return (1);
}

static void	ft_erreur(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

static void	ft_usage(void)
{
	write(1, "usage: ./fillit source_file\n", 28);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		nb_pieces;
	t_piece	vect[27];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_erreur();
			return (0);
		}
		nb_pieces = ft_read(fd, vect);
		if (nb_pieces == -1)
			ft_erreur();
		else
			ft_create_map(vect, nb_pieces);
	}
	else
		ft_usage();
	return (0);
}
