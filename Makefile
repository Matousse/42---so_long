NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c movement.c display.c parse_the_map.c verify_the_map.c verify_the_map_geometry.c verify_the_pce_identifiers.c flood_fill.c
OBJ = $(SRCS:.c=.o)

MLX_DIR = /home/dmathis/42cursus/42_utils/mlx
MLX_LIB = -L$(MLX_DIR) -lmlx
MLX_FLAGS = -lXext -lX11 -lm -lz

LIBFT = libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
GNL = ./get_next_line/get_next_line.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GNL)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(PRINTF) $(GNL) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make all -C ./libft

$(PRINTF):
	make all -C ./ft_printf

$(GNL):
	make all -C ./get_next_line

clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	make clean -C ./get_next_line
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	make fclean -C ./get_next_line
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
