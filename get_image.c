#include "so_long.h"

void img_init(t_image *image, t_vars *vars)
{
	image->W.img = mlx_xpm_file_to_image(vars->mlx, "image/wall.xpm",
										 &image->W.width, &image->W.height);
	image->C.img = mlx_xpm_file_to_image(vars->mlx, "image/coin.xpm",
										 &image->C.width, &image->C.height);
	image->E.img = mlx_xpm_file_to_image(vars->mlx, "image/exit.xpm",
										 &image->E.width, &image->E.height);
	image->P.img = mlx_xpm_file_to_image(vars->mlx, "image/player.xpm",
										 &image->P.width, &image->P.height);
	image->F.img = mlx_xpm_file_to_image(vars->mlx, "image/floor.xpm",
										 &image->F.width, &image->F.height);
}

void get_image(t_map *map, t_image *image, t_vars *vars)
{
	int x;
	int y;

	x = -1;
	img_init(image, vars);
	while (++x < map->height)
	{
		y = -1;
		while (++y < map->width)
		{
			if(map->map[x][y] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, image->W.img,x
				* 32, y * 32);
			if(map->map[x][y] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, image->F.img,x
				* 32, y * 32);
			if(map->map[x][y] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, image->C.img,x
				* 32, y * 32);
			if(map->map[x][y] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, image->P.img,x
				* 32, y * 32);
			if(map->map[x][y] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, image->E.img,x
				* 32, y * 32);
		}
	}
}