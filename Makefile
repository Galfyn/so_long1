NAME = so_long

SRC = so_long.c	error.c	ft_read_map.c	ft_get_image.c	ft_move.c

OBJ = $(patsubst %.c,%.o,$(SRC))

CFLAGS = -Wall -Wextra -Werror

all : mlx libft $(NAME)

$(NAME) : $(OBJ)
	 gcc -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $@

%.o : %.c
	gcc $(CFLAGS) -Imlx -c $< -o $@

libft :
	make -C Libft/

mlx :
	make -C mlx/

clean :
	rm -f $(OBJ) $(OBJ_B)
	make clean -C Libft/
	make clean -C mlx/

fclean : clean
	rm -f $(NAME)
	rm -f Libft/libft.a
	rm -f mlx/libmlx.a
re : fclean all

.PHONY : clean fclean libft re all mlx