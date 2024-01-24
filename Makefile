# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 16:32:28 by jbrousse          #+#    #+#              #
#    Updated: 2024/01/24 18:06:43 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## 	COMPILE	 ##
###############

CC		=	gcc
CFLAGS	=	-g3 -Wall -Werror -Wextra -I

##############
##  SOURCE	##
##############

SRC_DIR			=	sources/

SRC_SSTACK_DIR	=	sStack/
SRC_SSTACK_LIST	=	s_clear_stk.c		\
					s_getat_stk.c		\
					s_init_stk.c		\
					s_isempty_stk.c		\
					s_isfull_stk.c		\
					s_len_stk.c			\
					s_pop_stk.c			\
					s_push_stk.c		\
					s_update_at_stk.c	\
SRC_SSTACK		=	$(addprefix $(SRC_DIR), $(SRC_SSTACK_DIR))

SRC_LIST		=	$(SRC_SSTACK)
SRC				=	$(addprefix $(SRC_DIR), $(SRC_LIST))

################
##	INCLUDES  ##
################

INCLUDES	=	includes/

################
##	OBJ/NAME  ##
################

NAME		=	StackFT.a

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

################
##	PROGRESS  ##
################

TOTAL_SRCS		=	$(words $(SRC))
COMPILED_SRCS	=	0

define print_progress
	@echo -n "$(COLOR_BLUE)Compiling: [$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		[ $$i -le $$(($(1)*25/$(2))) ] && echo -n "#" || echo -n "."; \
	done
	@echo -n "$(COLOR_BLUE)] $(1)/$(2)$(COLOR_RESET)\r"
endef

##############
##	COLORS	##
##############

COLOR_RESET	=	\033[0m
COLOR_GREEN	=	\033[32m
COLOR_BLUE	=	\033[34m
COLOR_RED	=	\033[31m

#############
##	RULES  ##
#############

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS))

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\n$(COLOR_GREEN)Compilation complete !$(COLOR_RESET)"

clean: 
	@rm -fr  $(OBJ_DIR)
	@rm -f norme_log
	@echo "$(COLOR_GREEN)Remove Object complete !$(COLOR_RESET)"

fclean: clean cleanso 
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)Remove libft complete !$(COLOR_RESET)"

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC_DIR) $(INCLUDES) > norme_log ; \
	if grep -q "Error" norme_log; then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \
	
cleanso:
	@rm -f libft.so

.PHONY: all clean fclean re