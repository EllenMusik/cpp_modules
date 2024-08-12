NAME = ex01
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
#DEBUG = -fsanitize=address -g
RM = rm -rf

SRC_DIR	=	./src
OBJ_DIR	=	./obj

FILES	=  main

SRC		=	$(addsuffix .cpp, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJ		=	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(DEBUG) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $<

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re