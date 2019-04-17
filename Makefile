# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/04 17:40:52 by mminkjan       #+#    #+#                 #
#    Updated: 2019/04/09 18:42:44 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES = libft/
LIB = libft/ -lft
FTS = main.c manage_grid.c validate_file.c setting_tetros.c ft_tetnew.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	make re -C libft/
	gcc -I $(FILES) -L $(LIB) $(FTS) $(FLAGS) -o$(NAME)

clean :
	make clean -C libft/
	rm -f *#
	rm -f *~

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all

add : fclean
	@ git add $(FILES) $(FTS) fillit.h Makefile author
	git status
	
push :
ifdef MSG
	@ git commit -m "$(MSG)"
	git push
else 
    @ echo "usage ex: make push MSG="<message>"
endif
