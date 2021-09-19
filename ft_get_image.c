/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:48:32 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/19 06:59:31 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_img_init(t_game *game)
{
	game->W.img = mlx_xpm_file_to_image(game->vars.mlx, "image/wall.xpm",
			 &game->W.width, &game->W.height);
	game->C.img = mlx_xpm_file_to_image(game->vars.mlx, "image/coin.xpm",
			 &game->C.width, &game->C.height);
	game->E.img = mlx_xpm_file_to_image(game->vars.mlx, "image/exit.xpm",
			 &game->E.width, &game->E.height);
	game->P.img = mlx_xpm_file_to_image(game->vars.mlx, "image/player.xpm",
			 &game->P.width, &game->P.height);
	game->F.img = mlx_xpm_file_to_image(game->vars.mlx, "image/floor.xpm",
			 &game->F.width, &game->F.height);
}

static void	ft_get_coin_player_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->F.img, x * 32, y * 32);
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->C.img, x * 32, y * 32);
	}
	if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->F.img, x * 32, y * 32);
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->P.img, x * 32, y * 32);
	}
	if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->F.img, x * 32, y * 32);
		mlx_put_image_to_window(game->vars.mlx, game->vars.win,
			game->E.img, x * 32, y * 32);
	}
}

int	ft_get_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	ft_img_init(game);
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->W.img, x * 32, y * 32);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->F.img, x * 32, y * 32);
			ft_get_coin_player_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
