/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:24:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/24 18:18:42 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int					read_instructions(unsigned char *line, t_env *env, int fd,
					t_player *player)
{
	unsigned int	i;
	ssize_t			ret;

	i = PROG_NAME_LENGTH + 8;
	player->header.prog_size = ft_getbinary_numb(line, i, sizeof(int));
	if (player->header.prog_size > CHAMP_MAX_SIZE
			|| player->header.prog_size == 0)
	{
		env->cycles = player->header.prog_size;
		if (player->header.prog_size > CHAMP_MAX_SIZE)
			return (ft_read_errors(env, line, fd, 6));
		else
			return (ft_read_errors(env, line, fd, 8));
	}
	i = COMMENT_LENGTH + PROG_NAME_LENGTH + 16;
	if (lseek(fd, 0, SEEK_END) - (off_t)i != (off_t)player->header.prog_size)
		return (ft_read_errors(env, line, fd, 7));
	lo_strdel((char **)&line);
	if (!(line = (unsigned char *)lo_strnew(player->header.prog_size)))
		exit(EXIT_FAILURE);
	lseek(fd, i, SEEK_SET);
	ret = read(fd, line, player->header.prog_size);
	player->origin_code = line;
	player->origin_code[player->header.prog_size] = 0;
	return (1);
}

int					read_header(unsigned char *line,
					t_player *player, int fd, t_env *env)
{
	unsigned int	i;
	unsigned int	j;

	player->header.magic = ft_getbinary_numb(line, 0, sizeof(int));
	if (player->header.magic != COREWAR_EXEC_MAGIC)
		return (ft_read_errors(env, line, fd, 3));
	i = sizeof(int);
	j = 0;
	while (line[i] != 0 && j <= PROG_NAME_LENGTH)
		player->header.prog_name[j++] = (char)line[i++];
	if (j > PROG_NAME_LENGTH)
		return (ft_read_errors(env, line, fd, 4));
	player->header.prog_name[j] = 0;
	i = PROG_NAME_LENGTH + 12;
	j = 0;
	while (line[i] != 0 && j <= COMMENT_LENGTH)
		player->header.comment[j++] = (char)line[i++];
	if (j > COMMENT_LENGTH)
		return (ft_read_errors(env, line, fd, 5));
	player->header.comment[j] = 0;
	return (1);
}

int					parse_champ(unsigned char *line, t_env *env, int fd)
{
	static int		i = 0;

	if (i == MAX_PLAYERS)
		return (ft_read_errors(env, line, fd, 2));
	if (read_header(line, &env->players[i], fd, env) == 0)
		return (0);
	if (read_instructions(line, env, fd, &env->players[i]) == 0)
		return (0);
	i++;
	return (1);
}

int					read_champions(t_env *env, char *arg)
{
	unsigned char	*line;
	size_t			n_bytes;
	int				fd;

	if ((fd = open(arg, O_RDONLY)) == -1)
		return (ft_read_errors(env, NULL, fd, 0));
	n_bytes = COMMENT_LENGTH + PROG_NAME_LENGTH + 16;
	if (!(line = (unsigned char *)lo_strnew((size_t)(n_bytes))))
		exit(EXIT_FAILURE);
	if (read(fd, line, n_bytes) < 0)
		return (ft_read_errors(env, line, fd, 0));
	if (lseek(fd, 0, SEEK_END) < (off_t)n_bytes)
		return (ft_read_errors(env, line, fd, 1));
	if (!parse_champ(line, env, fd))
		return (0);
	close(fd);
	line = NULL;
	return (1);
}

int					read_params(t_env *env, int ac, char *av[])
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (detect_champion(av[i]) == 1)
		{
			if (!read_champions(env, av[i]))
				exit(EXIT_SUCCESS);
			++j;
		}
		i++;
	}
	if (env->nbr_players == 0)
	{
		corewar_usage();
		exit(EXIT_SUCCESS);
	}
	return (1);
}
