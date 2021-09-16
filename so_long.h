
#ifndef SO_LONG_H
#define SO_LONG_H
# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
//typedef struct s_data{
//	void	*img;
//	char 	*adrr;
//	int 	bits_per_pixel;
//	int 	line_lenght;
//	int		endinan;
//}	t_data;

typedef struct s_vars{
	void 	*mlx;
	void 	*win;
}	t_vars;
typedef struct s_coor{
	int	x;
	int y;
	int nb;
}	t_coor;
typedef struct s_xmp{
	void 	*img;
	int		width;
	int 	height;
}	t_xmp;
typedef struct s_image{
	t_xmp P;
	t_xmp E;
	t_xmp W;
	t_xmp C;
	t_xmp F;
}t_image;
typedef struct s_map{
	char	**map;
	int		width;
	int		height;
	int		coin;
	t_coor	player;
	t_coor 	out;

}t_map;


void	hand_map(int argc, char **argv, t_map *map);
void	error(char *msg);
void	read_map(char **argv, t_map *map);
void	get_image(t_map *map, t_image *image, t_vars *vars);

#endif