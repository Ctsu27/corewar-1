# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 11:32:53 by clrichar          #+#    #+#              #
#    Updated: 2018/07/07 15:34:59 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			libke.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR			:=			srcs
INC_DIR			:=			./includes
OBJ_DIR			:=			./obj

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #
SRC_NAME		:=			ke_memset.c			\
							ke_bzero.c			\
							ke_memcpy.c			\
							ke_memccpy.c		\
							ke_memmove.c		\
							ke_memchr.c			\
							ke_memcmp.c			\
							ke_nothing.c		\
							ke_strlen.c			\
							ke_str2len.c		\
							ke_strclen.c		\
							ke_strnlen.c		\
							ke_strdup.c			\
							ke_strndup.c		\
							ke_strcpy.c			\
							ke_strncpy.c		\
							ke_strcat.c			\
							ke_strncat.c		\
							ke_strlcat.c		\
							ke_strchr.c			\
							ke_strrchr.c		\
							ke_strstr.c			\
							ke_strnstr.c		\
							ke_strcmp.c			\
							ke_strncmp.c		\
							ke_atoi.c			\
							ke_isalpha.c		\
							ke_isdigit.c		\
							ke_isprint.c		\
							ke_isalnum.c		\
							ke_isascii.c		\
							ke_toupper.c		\
							ke_tolower.c		\
							ke_memalloc.c		\
							ke_memdel.c			\
							ke_strnew.c			\
							ke_strdel.c			\
							ke_free_str2.c		\
							ke_strclr.c			\
							ke_striter.c		\
							ke_striteri.c		\
							ke_strmap.c			\
							ke_strmapi.c		\
							ke_strequ.c			\
							ke_strnequ.c		\
							ke_strsub.c			\
							ke_strjoin.c		\
							ke_strtrim.c		\
							ke_strsplit.c		\
							ke_itoa.c			\
							ke_putchar.c		\
							ke_putstr.c			\
							ke_putendl.c		\
							ke_putnbr.c			\
							ke_putchar_fd.c		\
							ke_putuchar_fd.c	\
							ke_putstr_fd.c		\
							ke_putendl_fd.c		\
							ke_putnbr_fd.c		\
							ke_putunbr_fd.c		\
							ke_strjoin_free.c	\
							ke_get_next_line.c	\
							ke_itoa_base.c		\
							ke_swap.c
	
SRC_ALL			:= 			$(addprefix $(SRC_DIR)/,$(SRC_NAME:.c=.o))

OBJ				:=			$(addprefix $(OBJ_DIR)/,$(SRC_ALL:.c=.o))
NB				:=			$(words $(SRC_ALL))
INDEX			:=			0

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC				:=			gcc
CFLAGS			:=			-Wall -Wextra -Werror -I$(INC_DIR)
HEAD			:=			includes/libft.h

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					$(NAME)

$(NAME):				$(OBJ_DIR) $(HEAD) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "[ 100%% ] %s                                                       \n" "libft.a - part III"


$(OBJ_DIR)/%.o:			 %.c
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[ %d%% ] %s :: %s        \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/stdio
	@mkdir -p $(OBJ_DIR)/srcs

clean:
	@rm -rf $(OBJ_DIR)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"


fclean: 				clean
	@rm -rf $(NAME)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"


re:
	@$(MAKE) fclean
	@$(MAKE)


.PHONY: all clean fclean re build cbuild
