/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:37:43 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/19 07:52:01 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_struct_init(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->coin = 0;
	game->out = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->p_nb = 0;
}

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

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		ft_move_w(game);
	if (keycode == 0)
		ft_move_a(game);
	if (keycode == 1)
		ft_move_s(game);
	if (keycode == 2)
		ft_move_d(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_struct_init(&game);
	ft_check_arg(argc, argv);
	ft_read_map(argv, &game);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx, (game.width * 32),
			(game.height * 32), "so_long");
	ft_get_image(&game);
	mlx_key_hook(game.vars.win, key_hook, &game);
	mlx_loop(game.vars.mlx);
}
