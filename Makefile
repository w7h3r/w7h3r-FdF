NAME= FdF
CC= cc
CFLAGS= -Wall -Wextra -Werror
MLXFLAGS= -lXext -lX11 -lm
LIBFT= libft.a
PRINTF= libft.a
MLX= libmlx.a
SRC= src/init.c \
	 src/main.c \
	 read_data.c \
	 lib/get_next_line.c \
	 lib/get_next_line_utils.c \
	 lib/get_next_line.h

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C lib/libft/

$(PRINTF):
	make -C lib/ft_printf/

$(MLX):
	make -C lib/minilibx/

re: fclean all

clean:
	make -C lib/libft/ clean
	make -C lib/ft_printf/ clean
	make -C lib/minilibx/ clean

fclean: clean
	rm -rf $(NAME)
	make -C lib/libft/ fclean
	make -C lib/ft_printf/ fclean
	make -C lib/minilibx/ fclean

.PHONY: all lib re clean fclean
