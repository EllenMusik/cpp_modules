NAME = ex03
CC = c++
#CFLAGS = -Wall -Werror -Wextra -std=c++98
#DEBUG = -fsanitize=adress -g#RobotomyRequestForm PresidentialPardonForm
RM = rm -rf

SRC_DIR	=	./src
OBJ_DIR	=	./obj

FILES	=  main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm Intern

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