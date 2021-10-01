/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 06:51:25 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/20 20:26:42 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>

typedef struct s_vars{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_xmp{
	void	*img;
	int		width;
	int		height;
}	t_xmp;

typedef struct s_xmp_p{
	void	*stay;
	void	*left;
	void	*right;
	void	*up;
	void	*down;
	int		width;
	int		height;
}	t_xmp_p;

typedef struct s_game{
	t_vars	vars;
	char	**map;
	int		width;
	int		height;
	int		coin;
	int		p_x;
	int		p_y;
	int		p_nb;
	int		out;
	int		move;
	t_xmp_p	P;
	t_xmp	E;
	t_xmp	W;
	t_xmp	C;
	t_xmp	F;
}t_game;

void	error(char *msg);
void	ft_read_map(char **argv, t_game *game);
int		ft_get_image(t_game *game);
void	ft_move_w(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_d(t_game *game);

#endif
