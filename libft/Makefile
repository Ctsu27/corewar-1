# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 11:33:20 by clrichar          #+#    #+#              #
#    Updated: 2018/07/07 12:02:21 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=			libft.a
TMP				:=			liblo_pr.a

MK_PR			:=			libftprintf.a
MK_KE			:=			libke.a
MK_LO			:=			liblot.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

LIB_KE			:=			./libke
LIB_LO			:=			./liblot
LIB_PR			:=			./ft_printf

#==============================================================================#
#------------------------------------------------------------------------------#
#                                   RULES                                      #

all:					$(NAME)

$(NAME):				$(MK_PR) $(MK_LO) $(MK_KE)
	@libtool -static -o $(TMP)  $(LIB_LO)/liblot.a $(LIB_PR)/libftprintf.a
	@ranlib $(TMP)
	@libtool -static -o $(NAME) $(LIB_KE)/libke.a $(TMP)
	@ranlib $(NAME)
	@rm $(TMP)

$(MK_PR):
	@make -C $(LIB_PR)

$(MK_KE):
	@make -C $(LIB_KE)

$(MK_LO):
	@make -C $(LIB_LO)

clean:
	@make -C $(LIB_PR) clean
	@make -C $(LIB_KE) clean
	@make -C $(LIB_LO) clean
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"


fclean: 				clean
	@make -C $(LIB_PR) fclean
	@make -C $(LIB_KE) fclean
	@make -C $(LIB_LO) fclean
	@rm -f $(NAME)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"


re:
	@$(MAKE) fclean
	@$(MAKE)


.PHONY: all clean fclean re build cbuild
