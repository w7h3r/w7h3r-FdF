NAME= FdF
CC= cc
CFLAGS= -Wall -Wextra -Werror
MLXFLAGS= -lXext -lX11 -lm
LIBFT= lib/libft/libft.a
PRINTF= lib/ft_printf/libftprintf.a
MLX= lib/minilibx/libmlx.a
SRC= src/init.c \
	 src/main.c \
	 src/read_data.c \
	 src/read_data_utils.c \
	 src/projection.c \
	 src/draw.c \
	 src/misc_utils.c \
	 lib/get_next_line/get_next_line.c \
	 lib/get_next_line/get_next_line_utils.c \

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS)  -o $(NAME)

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
	rm -rf $(OBJ)
	make -C lib/libft/ clean
	make -C lib/ft_printf/ clean
	make -C lib/minilibx/ clean

fclean: clean
	rm -rf $(NAME)
	make -C lib/libft/ fclean
	make -C lib/ft_printf/ fclean

.PHONY: all lib re clean fclean
