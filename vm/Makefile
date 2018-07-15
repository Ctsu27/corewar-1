# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 13:58:48 by clrichar          #+#    #+#              #
#    Updated: 2018/07/07 13:58:49 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			corewar

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR			:=			srcs
INST_DIR		:=			srcs/instructions
VISU_DIR		:=			srcs/visualizer
INC_DIR			:=			includes/
OBJ_DIR			:=			./obj
LIB_DIR			:=			../libft
INC_LIB_DIR		:=			../libft/liblot/includes

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

SRC_NAME		:=			vm.c						\
							traduction.c				\
							scan_instruction.c			\
							move.c						\
							living.c					\
							instruction.c				\
							instruction_value.c			\
							initialize.c				\
							game.c						\
							arena.c						\
							check_players.c				\
							prepare_players.c			\
							read_players.c				\
							options.c					\
							name_dump.c					\
							read_errors.c				\
							verbosity.c					\
							util.c						\

INST_NAME		:=			op.c 						\
							ft_live.c					\
							ft_aff_op.c					\
							ft_fork.c					\
							ft_longload.c				\
							ft_load.c					\
							ft_op_add.c					\
							ft_op_and.c					\
							ft_op_or.c					\
							ft_op_sub.c					\
							ft_op_xor.c					\
							ft_store.c					\
							ft_zjump.c					\

VISU_NAME		:=			v_main.c					\
							v_arena.c					\
							v_player.c					\
							v_pcolor.c					\
							v_process.c					\
							v_info.c					\
							v_name.c					\
							v_store.c					\
							v_key.c						\
							v_finish.c					\

SRC_SRC			:=			$(addprefix $(SRC_DIR)/,$(SRC_NAME:.c=.o))
INST_SRC		:=			$(addprefix $(INST_DIR)/,$(INST_NAME))
VISU_SRC		:=			$(addprefix $(VISU_DIR)/,$(VISU_NAME))

SRC_ALL			:=			$(SRC_SRC)				\
							$(INST_SRC)				\
							$(VISU_SRC)				\

OBJ				:=			$(addprefix $(OBJ_DIR)/,$(SRC_ALL:.c=.o))
NB				:=			$(words $(SRC_ALL))
INDEX			:=			0

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC				:=			gcc
CFLAGS			:=			-Wall -Wextra -Werror
OFLAGS			:=			-pipe
CFLAGS			+=			$(OFLAGS)
CLIB			:=			-L$(LIB_DIR) -lft -lncurses

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
	@printf '\033[33m[ READY ] %s\n\033[0m' "Compilation of $(NAME) is done ---               "


$(OBJ_DIR)/%.o:			%.c
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(INC_LIB_DIR) -o $@ -c $<
	@printf "[ %d%% ] %s :: %s                    		   \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/srcs/instructions
	@mkdir -p $(OBJ_DIR)/srcs/visualizer

lib:
	@make -C libft/ --no-print-directory


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
