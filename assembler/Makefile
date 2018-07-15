# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 15:08:30 by clrichar          #+#    #+#              #
#    Updated: 2018/07/07 15:34:21 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			asm

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR			:=			./srcs
INC_DIR			:=			./includes
OBJ_DIR			:=			./obj
LIB_DIR			:=			./../libft

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

SRC				:=			main.c				\
							assembler.c			\
							lst.c				\
							lst_label.c			\
							utils.c				\
							tool.c				\
							parsing.c			\
							parsing_champion.c	\
							check_champion.c	\
							take_param_value.c	\
							label_check.c		\
							label_void.c		\
							op.c

OBJ				:=			$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
NB				:=			$(words $(SRC))
INDEX			:=			0

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC				:=			gcc
CFLAGS			:=			-Wall -Wextra -Werror
OFLAGS			:=			-pipe
CFLAGS			+=			$(OFLAGS)
CLIB			:=			-L$(LIB_DIR) -lft

#==============================================================================#
#------------------------------------------------------------------------------#
#                                LIBRARY                                       #

L_FT			:=			$(LIB_DIR)


#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					$(NAME)


$(NAME):				$(OBJ_DIR) $(OBJ)
	@$(CC) $(OFLAGS) $(OBJ) $(CLIB) -o $(NAME)
	@printf '\033[33m[ READY ] %s\n\033[0m' "Compilation of $(NAME) is done ---"


$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<
	@printf "[ %d%% ] %s :: %s        \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"


fclean: 				clean
	@rm -rf $(NAME)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"


re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re build cbuild
