# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/04 17:40:52 by mminkjan       #+#    #+#                 #
#    Updated: 2020/03/02 13:29:39 by jesmith       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = ./libft/

LIB = libft/ -lft

SRCS = ./srcs/

SRCS_FILES = main manage_grid validate_file setting_tetros ft_tetnew

C_FILES = $(SRCS_FILES:=%$(SRCS)%.c)

O_FILES = $(CFILES:%.c=%.o)

HEADERS = includes/fillit.h

FLAGS = -Wall -Wextra -Werror

ADD_FILES = Makefile author

all: $(NAME)

%.o: %.c
	@gcc -g -c $(FLAGS) $@ $<

$(NAME) :
	@make re -C $(LIBFT)
	@gcc -g -I $(LIBFT) -L $(LIB) $(C_FILES) $(FLAGS) $(NAME)
	@rm -f $(O_FILES)

clean :
	@make clean -C $(LIBFT)
	@rm -f $(OFILES)
	@rm -f *#
	@rm -f *~
	@rm -f *.DS_Store
	@rm -Rf .vscode

fclean : clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re : fclean all

add : fclean
	@ git add $(C_FILES) $(LIBFT) $(HEADERS) $(ADD_FILES)
	git status
	
push :
ifdef MSG
	@ git commit -m "$(MSG)"
	git push
else 
    @ echo "usage ex: make push MSG="<message>"
endif
