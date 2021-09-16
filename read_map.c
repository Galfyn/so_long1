#include "so_long.h"

static void count_size(char **argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);

	while (get_next_line(fd, &line) > 0)
		map->height++;
	map->width = (int)ft_strlen(line);
	free(line);
	close(fd);
}
void pars_map(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (++x != map->height)
	{
		y = 0;
		while (++y != map->width - 1)
		{
			if (map->map[x][y] == 'P')
			{
				map->player.x = x;
				map->player.y = y;
				map->player.nb+= 1;
			}
			if (map->map[x][y] == 'E')
			{
				map->out.x = x;
				map->out.y = y;
				map->out.nb+= 1;
			}
			if (map->map[x][y] == 'C')
				map->coin++;
			if (!ft_strchr("10EPC", map->map[x][y]))
				error("Map error");
		}
	}
}
void validation_map(t_map *map)
{
	int x;
	int y;

	x = -1;
	y = 0;

	while (++x != map->height)
		if (map->map[x][y] != '1' || map->map[x][map->width - 1] != '1')
			error("Map error");
	while (++y != map->width)
		if (map->map[0][y] != '1' || map->map[map->height][y] != '1')
			error("Map error");
	pars_map(map);
	if (map->player.nb != 1 || map->out.nb != 1 || map->coin <= 0)
		error("Map error");


}
void read_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int 	i;

	i = 0;

	count_size(argv, map);
	map->map = malloc((map->width + 1) * sizeof(char *));
	if (!map->map)
		error("Failed to allocate memory");
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		map->map[i] = line;
		if (map->width != (int) ft_strlen(map->map[i]))
			error("Map error");
		i++;
	}
	map->map[i] = line;
	free(line);
	close(fd);
	validation_map(map);
}