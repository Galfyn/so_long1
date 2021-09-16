#include "so_long.h"

void map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->coin = 0;
	map->out.nb = 0;
	map->player.nb = 0;
	map->out.x = 0;
	map->out.y = 0;
	map->player.x = 0;
	map->player.y = 0;
}

//int key_hook(int keycode)
//{
//	if(keycode == 53)
//		exit(1);
//	if(keycode == 1)
//		printf("oendor chushka");
//	return (1);
//}
void game_init(t_map *map, t_vars *vars, t_image *image)
{

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, ((map->height + 1) * 32),
								(map->width * 32),"so_long");
	get_image(map, image, vars);

//	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_loop(vars->mlx);
}


int main(int argc, char **argv)
{
	t_map	map;
	t_vars	vars;
	t_image image;

	map_init(&map);
	hand_map(argc, argv, &map);
	game_init(&map, &vars, &image);

}
