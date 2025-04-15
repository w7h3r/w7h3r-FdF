NAME= fdf
NAME_BONUS = fdf_bonus
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
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
	 src/color.c \
	 src/hooks.c \
	 src/draw_utils.c \
	 lib/get_next_line/get_next_line.c \
	 lib/get_next_line/get_next_line_utils.c \

SRC_BONUS = src_bonus/init_bonus.c \
			src_bonus/main_bonus.c \
			src_bonus/read_data_bonus.c \
			src_bonus/read_data_utils_bonus.c \
			src_bonus/projection_bonus.c \
			src_bonus/draw_bonus.c \
			src_bonus/misc_utils_bonus.c \
			src_bonus/color_bonus.c \
			src_bonus/hooks_bonus.c \
			src_bonus/draw_utils_bonus.c \
			lib/get_next_line/get_next_line.c \
			lib/get_next_line/get_next_line_utils.c \

OBJ= $(SRC:.c=.o)
OBJ_BONUS= $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS)  -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS)  -o $(NAME_BONUS)

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
	rm -rf $(OBJ) $(OBJ_BONUS)
	make -C lib/libft/ clean
	make -C lib/ft_printf/ clean
	make -C lib/minilibx/ clean

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make -C lib/libft/ fclean
	make -C lib/ft_printf/ fclean

.PHONY: all lib re clean fclean
