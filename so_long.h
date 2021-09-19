
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

//typedef struct s_coor{
//	int	x;
//	int y;
//	int nb;
//}	t_coor;

typedef struct s_xmp{
	void 	*img;
	int		width;
	int 	height;
}	t_xmp;

typedef struct s_game{
	t_vars	vars;
	char	**map;
	int		width;
	int		height;
	int		coin;
	int		p_x;
	int 	p_y;
	int 	p_nb;
	int 	out;
	t_xmp P;
	t_xmp E;
	t_xmp W;
	t_xmp C;
	t_xmp F;

}t_game;


void	ft_hand_map(int argc, char **argv, t_game *game);
void	error(char *msg);
void	ft_read_map(char **argv, t_game *game);
int		ft_get_image(t_game *game);
//void	ft_start_game(t_map *map, t_vars *vars, t_image *image);
void	ft_move_w(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);

#endif