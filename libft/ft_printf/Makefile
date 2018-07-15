# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 11:32:38 by clrichar          #+#    #+#              #
#    Updated: 2018/07/07 12:00:05 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			libftprintf.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR			:=			srcs
INC_DIR			:=			./includes
OBJ_DIR			:=			./obj

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #
SRC_NAME		:=			color.c							\
							attrib.c						\
							global_conversion.c				\
							ft_printf.c						\
							initialize.c					\
							integer_signed_conversion.c		\
							integer_unsigned_conversion.c	\
							precision_field.c				\
							scan.c							\
							unicod_conversion.c				\
	
SRC_ALL			:= 			$(addprefix $(SRC_DIR)/,$(SRC_NAME:.c=.o))

OBJ				:=			$(addprefix $(OBJ_DIR)/,$(SRC_ALL:.c=.o))
NB				:=			$(words $(SRC_ALL))
INDEX			:=			0

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC				:=			gcc
CFLAGS			:=			-Wall -Wextra -Werror -I$(INC_DIR)
HEAD			:=			includes/ft_printf.h

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					$(NAME)

$(NAME):				$(OBJ_DIR) $(HEAD) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "[ 100%% ] %s                                                                       \n" "libft.a - part I"


$(OBJ_DIR)/%.o:			 %.c
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[ %d%% ] %s :: %s        \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) 2>/dev/null; true
	@mkdir -p $(OBJ_DIR)/stdio 2>/dev/null; true
	@mkdir -p $(OBJ_DIR)/srcs 2>/dev/null; true

clean:
	@rm -rf $(OBJ_DIR) 2>/dev/null; true
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"


fclean: 				clean
	@rm -rf $(NAME) 2>/dev/null; true
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"


re:
	@$(MAKE) fclean
	@$(MAKE)


.PHONY: all clean fclean re build cbuild
