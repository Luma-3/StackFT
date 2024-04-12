# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 16:32:28 by jbrousse          #+#    #+#              #
#    Updated: 2024/04/12 11:42:47 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## 	COMPILE	 ##
###############

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I

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
					d_drop_stk.c		\
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

#################
##	 COLORS	   ##
#################

COLOR_RESET		=	\033[0m
COLOR_GREEN		=	\033[38;5;76m
COLOR_RED		=	\033[38;5;160m
COLOR_BLUE		=	\033[38;5;45m
COLOR_ORANGE	=	\033[38;5;220m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m

################
##	PROGRESS  ##
################

COMPILED_SRCS		:=	1

TOTAL_SRCS			:=	$(words $(SRC))


MAX_PATH_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' | awk '{print length}' | sort -nr | head -n1)
MAX_NAME_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' -exec basename {} \; | awk '{ print length }' | sort -nr | head -n1)

define progress_bar
	printf "$(COLOR_BLUE)Compiling: [$(COLOR_GREEN)"; \
	for i in $$(seq 1 $(4)); do \
		if [ $$i -le $$(($(1)*$(4)/$(2))) ]; then \
			printf "#"; \
		else \
			printf "."; \
		fi; \
	done; \
	printf "$(COLOR_BLUE)] $(BOLD)$(1)/$(2) $(COLOR_GREEN)$(3)$(COLOR_RESET)\r"
endef

define print_progress
	@$(eval WIDTH := $(shell tput cols))
	@$(eval LEN := $(shell expr $(WIDTH) - $(MAX_PATH_LENGTH) - 26))
	
	@printf "\033[2K"; \
	if [ $(LEN) -le 10 ]; then \
		printf "$(COLOR_BLUE)Compiling: $(BOLD)$(1)/$(2)$(COLOR_RESET)$(COLOR_GREEN) $(notdir $(3))$(COLOR_RESET)\r"; \
	else \
		$(call progress_bar,$(1),$(2),$(3),$(LEN)); \
	fi
endef

#############
##	RULES  ##
#############

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)Stackft is Ready !$(COLOR_RESET)"

clean: 
	@rm -fr  $(OBJ_DIR)
	@rm -f norme_log
	@echo "$(COLOR_RED)$(BOLD)Delete stackft objects$(COLOR_RESET)"


fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_RED)$(BOLD)Delete Stackft$(COLOR_RESET)"


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