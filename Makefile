# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 16:32:28 by jbrousse          #+#    #+#              #
#    Updated: 2024/03/28 18:54:10 by jbrousse         ###   ########.fr        #
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

SRC_SSTACK_DIR	=	sstack/
SRC_SSTACK_LIST	=	s_clear_stk.c		\
					s_init_stk.c		\
					s_isempty_stk.c		\
					s_isfull_stk.c		\
					s_len_stk.c			\
					s_pop_stk.c			\
					s_push_stk.c		\
					s_rollup_stk.c		\
					s_rolldown_stk.c	\
					s_swap_stk.c
SRC_SSTACK		=	$(addprefix $(SRC_SSTACK_DIR), $(SRC_SSTACK_LIST))

SRC_DSTACK_DIR	=	dstack/
SRC_DSTACK_LIST	=	d_clear_stk.c		\
					d_init_stk.c		\
					d_isempty_stk.c		\
					d_pop_stk.c			\
					d_push_stk.c		\
					d_swap_stk.c
SRC_DSTACK		=	$(addprefix $(SRC_DSTACK_DIR), $(SRC_DSTACK_LIST))
SRC_LIST		=	$(SRC_SSTACK) \
					$(SRC_DSTACK)
SRC				=	$(addprefix $(SRC_DIR), $(SRC_LIST))

################
##	INCLUDES  ##
################

INCLUDES	=	includes/

################
##	OBJ/NAME  ##
################

NAME		=	stackft.a

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
	@mkdir -p $(OBJ_DIR)$(SRC_SSTACK_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DSTACK_DIR)


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

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)Remove StackFT complete !$(COLOR_RESET)"

re: fclean all

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC_DIR) $(INCLUDES) > norme_log ; \
	if grep -q "Error" norme_log; then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

.PHONY: all clean fclean re