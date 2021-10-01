/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:48:32 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/20 23:56:12 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_img(t_game *game)
{
	if (!game->P.stay)
		error("Failed to get image");
	if (!game->P.right)
		error("Failed to get image");
	if (!game->P.left)
		error("Failed to get image");
	if (!game->P.up)
		error("Failed to get image");
	if (!game->P.down)
		error("Failed to get image");
	if (!game->W.img)
		error("Failed to get image");
	if (!game->F.img)
		error("Failed to get image");
	if (!game->C.img)
		error("Failed to get image");
	if (!game->E.img)
		error("Failed to get image");
}

void	ft_img_init(t_game *game)
{
	game->W.img = mlx_xpm_file_to_image(game->vars.mlx, "image/wall.xpm",
			 &game->W.width, &game->W.height);
	game->C.img = mlx_xpm_file_to_image(game->vars.mlx, "image/coin.xpm",
			 &game->C.width, &game->C.height);
	game->E.img = mlx_xpm_file_to_image(game->vars.mlx, "image/exit.xpm",
			 &game->E.width, &game->E.height);
	game->P.stay = mlx_xpm_file_to_image(game->vars.mlx, "image/player.xpm",
			 &game->P.width, &game->P.height);
	game->P.down = mlx_xpm_file_to_image(game->vars.mlx, "image/back.xpm",
			 &game->P.width, &game->P.height);
	game->P.up = mlx_xpm_file_to_image(game->vars.mlx, "image/up.xpm",
			 &game->P.width, &game->P.height);
	game->P.left = mlx_xpm_file_to_image(game->vars.mlx, "image/left.xpm",
			 &game->P.width, &game->P.height);
	game->P.right = mlx_xpm_file_to_image(game->vars.mlx, "image/right.xpm",
			 &game->P.width, &game->P.height);
	game->F.img = mlx_xpm_file_to_image(game->vars.mlx, "image/floor.xpm",
			 &game->F.width, &game->F.height);
	ft_check_img(game);
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
			game->P.stay, x * 32, y * 32);
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
