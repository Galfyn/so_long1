#include "so_long.h"

void	ft_move_w(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] != '1')
	{
		if (game->map[game->p_y - 1][game->p_x] == 'C')
			game->coin--;
		if (game->map[game->p_y - 1][game->p_x] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y - 1][game->p_x] != 'E')
		{
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y - 1][game->p_x] = 'P';
			game->p_y--;
		}
	}
}

void	ft_move_a(t_game *game)
{
	if (game->map[game->p_y][game->p_x - 1] != '1')
	{
		if (game->map[game->p_y][game->p_x - 1] == 'C')
			game->coin--;
		if (game->map[game->p_y][game->p_x - 1] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y][game->p_x - 1] != 'E')
		{
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y][game->p_x - 1] = 'P';
			game->p_x--;
		}

	}
}
void	ft_move_s(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] != '1')
	{
		if (game->map[game->p_y + 1][game->p_x] == 'C')
			game->coin--;
		if (game->map[game->p_y + 1][game->p_x] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y + 1][game->p_x] != 'E')
		{
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y + 1][game->p_x] = 'P';
			game->p_y++;
		}
	}
}
void	ft_move_d(t_game *game)
{
	if (game->map[game->p_y][game->p_x + 1] != '1' ||
		(game->map[game->p_y][game->p_x + 1] == 'E' && game->coin != 0))
	{
		if (game->map[game->p_y][game->p_x + 1] == 'C')
			game->coin--;
		if (game->map[game->p_y][game->p_x + 1] == 'E' && game->coin == 0)
			exit(0);
		if (game->map[game->p_y][game->p_x + 1] != 'E')
		{
			game->map[game->p_y][game->p_x] = '0';
			game->map[game->p_y][game->p_x + 1] = 'P';
			game->p_x++;
		}

	}
}