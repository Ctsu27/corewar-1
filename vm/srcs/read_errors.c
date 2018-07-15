/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 15:46:09 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/24 18:20:14 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_read_errors_bis(t_env *env, unsigned char opt)
{
	if (opt == 7)
		ft_printf("The champion has a code size different from the header's"
				" one\n");
	else if (opt == 8)
		ft_printf("the champion's size is too small (%u byte)\n",
				env->cycles);
}

int			ft_read_errors(t_env *env, unsigned char *line, int fd,
		unsigned char opt)
{
	if (line != NULL)
		lo_strdel((char **)&line);
	if (fd > 2)
		close(fd);
	ft_printf("Error: ");
	if (opt == 0)
		ft_printf("The .cor file is not a valide file.\n");
	else if (opt == 1)
		ft_printf("the .cor file is too small to be a champion.\n");
	else if (opt == 2)
		ft_printf("There is too many champions.\n");
	else if (opt == 3)
		ft_printf("The magic number is not correct.\n");
	else if (opt == 4)
		ft_printf("The name of the champion is too long.\n");
	else if (opt == 5)
		ft_printf("The comment of the champion is too long.\n");
	else if (opt == 6)
		ft_printf("the champion's size is too big (%u bytes > %u bytes)\n",
				env->cycles, CHAMP_MAX_SIZE);
	else
		ft_read_errors_bis(env, opt);
	return (0);
}
