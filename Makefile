NAME = connect4

CC = cc

OBJ_DIR = objects/

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g #-fsanitize=address,leak,undefined

SRC = main.c prompt_player.c ai_turn.c grid_handling.c check_grid.c init.c

HEADERs = 

OBJ_DIR = objects/

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

DEPS = $(OBJS:.o=.d)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT):
	make -C libft

run: all
	./$(NAME) 6 7

runval: CFLAGS:= -Wall -Wextra -Werror -g
runval: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 6 7

runsan: CFLAGS:= -g -fsanitize=address,undefined,leak
runsan: all
	./$(NAME) 6 7



clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean:
	rm -rf $(OBJ_DIR) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re
