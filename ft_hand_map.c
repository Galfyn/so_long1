/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hand_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:49:39 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/19 06:49:41 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_arg(int argc, char **argv)
{
	int		fd;
	int		i;

	i = (int)ft_strlen(argv[1]);
	if (argc < 2)
		error("Not enough arguments");
	if (argc > 2)
		error("Extra arguments specified");
	if (argv[1][i - 1] != 'r' && argv[1][i - 1] != 'e' && argv[1][i - 1] &&
		argv[1][i - 1] != 'b' && argv[1][i - 1] != '.')
		error("Invalid file extension");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Failed to read the map");
	else
		close(fd);
}

void	ft_hand_map(int argc, char **argv, t_game *game)
{
	ft_check_arg(argc, argv);
	ft_read_map(argv, game);
}
