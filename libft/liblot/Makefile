# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 11:33:09 by clrichar          #+#    #+#              #
#    Updated: 2018/07/07 12:01:39 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			liblot.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR			:=			srcs
INC_DIR			:=			./includes
OBJ_DIR			:=			./obj

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #
SRC_NAME		:=			lo_lst_stepback.c			\
							lo_lst_reset.c				\
							lo_lst_advance.c			\
							lo_is_number.c				\
							lo_is_whitespace.c			\
							lo_atoi_unsignedlong.c		\
							lo_fill_str_c.c				\
							lo_strhexa_int.c			\
							lo_unsigned_strdup.c		\
							lo_lst_cnttdel.c			\
							lo_abs.c					\
							lo_word_nbr.c				\
							lo_strlen_c.c				\
							lo_rint_tab.c				\
							lo_2d_array.c				\
							lo_strcmp_n.c				\
							lo_is_integer.c				\
							lo_lst_del_all.c			\
							lo_lst_create.c				\
							lo_get_next_line.c			\
							lo_lst_int_copy.c			\
							lo_strcmp_c.c				\
							lo_lst_getend.c				\
							lo_lst_del_last.c			\
							lo_lst_del_one.c			\
							lo_lst_reverse.c			\
							lo_strdel_two.c				\
							lo_putwstr.c				\
							lo_str_replace.c			\
							lo_base_conv.c				\
							lo_putwchar.c				\
							lo_power.c					\
							lo_putlong_unsigned.c		\
							lo_itoa_base_unsigned.c		\
							lo_putlong.c				\
							lo_putnbr_abs.c				\
							lo_int_length.c				\
							lo_toupper_str.c			\
							lo_itoa_base.c				\
							lo_strjoin_free.c			\
							lo_free_strtab.c			\
							lo_strnew_free.c			\
							lo_strsearch.c				\
							lo_putnbrn.c				\
							lo_strdup_free.c			\
							lo_strsub_free.c			\
							lo_strlen_to.c				\
							lo_nbr_of_words.c			\
							lo_strtrim_c.c				\
							lo_strstr_int.c				\
							lo_lst_push_params.c		\
							lo_lst_last.c				\
							lo_lst_size.c				\
							lo_lst_add_end.c			\
							lo_swap_str.c				\
							lo_swap.c					\
							lo_sqrt.c					\
							lo_sort_params.c			\
							lo_recursive_factorial.c	\
							lo_range.c					\
							lo_print_params.c			\
							lo_is_negative.c			\
							lo_create_chartab.c			\
							lo_rchar_tab.c				\
							lo_atoi.c					\
							lo_bzero.c					\
							lo_isalnum.c				\
							lo_isalpha.c				\
							lo_isascii.c				\
							lo_isdigit.c				\
							lo_isprint.c				\
							lo_itoa.c					\
							lo_lst_add.c				\
							lo_lstiter.c				\
							lo_lst_new.c				\
							lo_memalloc.c				\
							lo_memchr.c					\
							lo_memmove.c				\
							lo_memcpy.c					\
							lo_memdel.c					\
							lo_putchar_fd.c				\
							lo_memset.c					\
							lo_putendl_fd.c				\
							lo_putchar.c				\
							lo_putendl.c				\
							lo_putnbr_fd.c				\
							lo_putstr_fd.c				\
							lo_strcat.c					\
							lo_strclr.c					\
							lo_strcpy.c					\
							lo_strequ.c					\
							lo_putnbr.c					\
							lo_strchr.c					\
							lo_putstr.c					\
							lo_strdel.c					\
							lo_memcmp.c					\
							lo_strlen.c					\
							lo_strncmp.c				\
							lo_strnew.c					\
							lo_strdup.c					\
							lo_strnequ.c				\
							lo_strlcat.c				\
							lo_strnstr.c				\
							lo_strsplit.c				\
							lo_strncpy.c				\
							lo_strsub.c					\
							lo_strncat.c				\
							lo_tolower.c				\
							lo_strtrim.c				\
							lo_toupper.c				\
							lo_strstr.c					\
							lo_strrchr.c				\
							lo_strjoin.c				\
							lo_strcmp.c					\
							lo_memccpy.c				\

	
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
	@printf "[ 100%% ] %s                                                       \n" "libft.a - part II"


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
