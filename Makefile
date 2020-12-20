NAME = lem-in
LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

INCLUDE = -I./include
INCLUDE += -I./libft/include

HEADERS = include/lem_in.h


SRCS = main.c
SRCS += copy_edges_nodes.c
SRCS += other_routes_find.c
SRCS += paths_find.c
SRCS += utils.c
SRCS += edges.c
SRCS += bellman_ford.c
SRCS += parsing.c
SRCS += nodes.c
SRCS += move_ants_and_print.c
SRCS += route_short.c
SRCS += graph_recovery.c
SRCS += crossover.c
SRCS += suurballe.c
SRCS += state_free.c

OBJS = $(SRCS:.c=.o)

SRCS_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS_PATH = $(addprefix $(OBJ_DIR)/,$(OBJS))


.PHONY: clean fclean all re make_lib

all: $(LIBFT) $(NAME)

$(LIBFT) : make_lib
	@mkdir -p $(OBJ_DIR)

make_lib:
	@make -C ./libft/

$(NAME): $(OBJS_PATH) $(LIBFT) $(HEADERS)
	$(CC) -o $@ $(OBJS_PATH) $(LIBFT) $(INCLUDE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS) Makefile
	$(CC) -o $@ -c $< $(INCLUDE) $(FLAGS)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ./libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all

.PHONY: make_lib clean fclean re
