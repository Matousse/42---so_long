NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ./get_next_line.c ./get_next_line_utils.c

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c \

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:  $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
