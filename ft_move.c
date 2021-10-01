/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:49:03 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/20 23:43:40 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_w(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] != '1')
	{
		if (game->map[game->p_y - 1][game->p_x] == 'C')
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, game->p_x * 32, (game->p_y - 1) * 32);
			game->coin--;
		}
		if (game->map[game->p_y - 1][game->p_x] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y - 1][game->p_x] != 'E')
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, game->p_x * 32, game->p_y * 32);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->P
				.up, game->p_x * 32, (game->p_y - 1) * 32);
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y - 1][game->p_x] = 'P';
			game->p_y--;
			game->move++;
		}
	}
}

void	ft_move_a(t_game *game)
{
	if (game->map[game->p_y][game->p_x - 1] != '1')
	{
		if (game->map[game->p_y][game->p_x - 1] == 'C')
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, (game->p_x - 1) * 32, game->p_y * 32);
			game->coin--;
		}
		if (game->map[game->p_y][game->p_x - 1] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y][game->p_x - 1] != 'E')
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, game->p_x * 32, game->p_y * 32);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->P
				.left, (game->p_x - 1) * 32, game->p_y * 32);
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y][game->p_x - 1] = 'P';
			game->p_x--;
			game->move++;
		}
	}
}

void	ft_move_s(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] != '1')
	{
		if (game->map[game->p_y + 1][game->p_x] == 'C')
		{
			game->coin--;
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, game->p_x * 32, (game->p_y + 1) * 32);
		}
		if (game->map[game->p_y + 1][game->p_x] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y + 1][game->p_x] != 'E')
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, game->p_x * 32, game->p_y * 32);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->P
				.down, game->p_x * 32, (game->p_y + 1) * 32);
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y + 1][game->p_x] = 'P';
			game->p_y++;
			game->move++;
		}
	}
}

void	ft_move_d(t_game *game)
{
	if (game->map[game->p_y][game->p_x + 1] != '1' ||
		(game->map[game->p_y][game->p_x + 1] == 'E' && game->coin != 0))
	{
		if (game->map[game->p_y][game->p_x + 1] == 'C')
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, (game->p_x + 1) * 32, game->p_y * 32);
			game->coin--;
		}
		if (game->map[game->p_y][game->p_x + 1] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y][game->p_x + 1] != 'E')
		{
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->F
				.img, game->p_x * 32, game->p_y * 32);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->P
				.right, (game->p_x + 1) * 32, game->p_y * 32);
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y][game->p_x + 1] = 'P';
			game->p_x++;
			game->move++;
		}
	}
}
