NAME= FdF
CC= cc
CFLAGS= -Wall -Wextra -Werror
MLXFLAGS= -lXext -lX11 -lm
LIBFT= libft.a
PRINTF= libft.a
MLX= libmlx.a

all: $(LIBFT) $(NAME)

lib:

re:

clean:

fclean:

.PHONY: all lib re clean fclean
