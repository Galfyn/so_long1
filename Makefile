NAME = so_long

SRC = so_long.c	hand_map.c	error.c read_map.c get_image.c

OBJ = $(patsubst %.c,%.o,$(SRC))

CFLAGS = -Wall -Wextra -Werror

all : libft  $(NAME)

$(NAME) : $(OBJ)
	 gcc -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $@

%.o : %.c
	gcc $(CFLAGS) -Imlx -c $< -o $@

libft :
	make -C Libft/
clean :
	rm -f $(OBJ) $(OBJ_B)
	make clean -C Libft/
	make clean -C mlx/

fclean : clean
	rm -f $(NAME)
	rm -f Libft/libft.a
	rm -f mlx/libmlx.a
re : fclean all

.PHONY : clean fclean libft re all