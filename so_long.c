/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:37:43 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/19 06:39:20 by galfyn           ###   ########.fr       */
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
	ft_hand_map(argc, argv, &game);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx, (game.width * 32),
			(game.height * 32), "so_long");
	ft_get_image(&game);
	mlx_key_hook(game.vars.win, key_hook, &game);
	mlx_loop_hook(game.vars.mlx, ft_get_image, &game);
	mlx_loop(game.vars.mlx);
}
