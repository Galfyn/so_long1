/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:49:17 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/20 23:58:30 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count_size(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		game->height++;
		game->width = (int) ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);
}

static void	ft_valid_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	while (++y < game->height)
		if (game->map[y][x] != '1' || game->map[y][game->width - 1] != '1')
			error("The vertical borders of the map are violated");
	x = -1;
	while (++x < game->width - 1)
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			error("The horizontal borders of the map are violated");
	if (game->p_nb != 1 || game->out != 1 || game->coin == 0)
		error("There must be 1 player, 1 exit, and at least 1 coin on the map");
}

static void	ft_pars_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width - 1)
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				game->p_nb++;
			}
			if (game->map[y][x] == 'E')
				game->out++;
			if (game->map[y][x] == 'C')
				game->coin++;
			if (!ft_strchr("01CPE", game->map[y][x]))
				error("Extra symbols in the map");
		}
	}
}

void	ft_read_map(char **argv, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	ft_count_size(argv, game);
	game->map = malloc((game->height + 1) * sizeof(char *));
	if (!game->map)
		error("Failed to allocate memory");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		game->map[i] = line;
		if (game->width != (int)ft_strlen(game->map[i]))
			error("The dimensions of the map do not meet the requirements");
		i++;
	}
	game->map[i] = line;
	free(line);
	close(fd);
	ft_pars_map(game);
	ft_valid_map(game);
}
