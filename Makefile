# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/04 17:40:52 by mminkjan       #+#    #+#                 #
#    Updated: 2020/03/02 13:44:53 by jesmith       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = libft/

LIB = libft/ -lft

SRCS = ./srcs/

SRCS_FILES = main manage_grid validate_file setting_tetros ft_tetnew

C_FILES = $(SRCS_FILES:%=$(SRCS)%.c)

OFILES = $(C_FILES:%.c=%.o)

HEADERS = includes/fillit.h

FLAGS = -Wall -Wextra -Werror

ADD_FILES = Makefile author 

all: $(NAME)

$(NAME) : $(O_FILES)
	@make re -C libft/
	@gcc -I $(FILES) -L $(LIB) $(C_FILES) $(FLAGS) -o$(NAME)
	@rm -f $(OFILES)

clean :
	@make clean -C libft/
	@rm -f *#
	@rm -f *~

fclean : clean
	@make fclean -C libft/
	@rm -f $(NAME)

re : fclean all

add : fclean
	@ git add $(FILES) $(FTS) $(HEADERS) $(ADD_FILES)
	git status
	
push :
ifdef MSG
	@ git commit -m "$(MSG)"
	git push
else 
    @ echo "usage ex: make push MSG="<message>"
endif
