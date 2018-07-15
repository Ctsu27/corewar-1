# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 13:56:01 by clrichar          #+#    #+#              #
#    Updated: 2018/07/07 13:56:03 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:=			/bin/zsh
NAME			:=			corewar

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

VM_DIR			:=			./vm
ASM_DIR			:=			./assembler
DSM_DIR			:=			./disassembler
LIB_DIR			:=			./libft


#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					libft.a vm

libft.a:
	@make -C $(LIB_DIR)

vm:						asm
	@make -C $(VM_DIR) --no-print-directory
	@cp $(VM_DIR)/corewar .

asm:					dsm
	@make -C $(ASM_DIR) --no-print-directory
	@cp $(ASM_DIR)/asm .

dsm:
	@make -C $(DSM_DIR) --no-print-directory
	@cp $(DSM_DIR)/dasm .

norm:
	@printf 'Usage please execute this command : norminette **/*.[ch]\n'

clean:
	@make -C $(LIB_DIR) clean --no-print-directory
	@make -C $(VM_DIR) clean --no-print-directory
	@make -C $(ASM_DIR) clean --no-print-directory
	@make -C $(DSM_DIR) clean --no-print-directory

fclean: 				clean
	@-rm ${LIB_DIR}/ft_printf/libftprintf.a 2>/dev/null; true
	@-rm ${LIB_DIR}/libke/libke.a 2>/dev/null; true
	@-rm ${LIB_DIR}/liblot/liblot.a 2>/dev/null; true
	@-rm ${LIB_DIR}/libft.a 2>/dev/null; true
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of libft.a is done ---"
	@-rm ${ASM_DIR}/asm 2>/dev/null; true
	@-rm ./asm 2>/dev/null; true
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of asm is done ---"
	@-rm ${DSM_DIR}/dasm 2>/dev/null; true
	@-rm ./dasm 2>/dev/null; true
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of dasm is done ---"
	@-rm ${VM_DIR}/corewar 2>/dev/null; true
	@-rm ./corewar 2>/dev/null; true
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of corewar is done ---"

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re build cbuild
