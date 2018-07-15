/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:38:57 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/05 19:23:38 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H
# include "op.h"
# include "libft.h"
# include <ncurses.h>

typedef struct			s_slot
{
	unsigned char		color;
	unsigned char		timer;
	bool				active;
}						t_slot;

typedef struct			s_win
{
	WINDOW				*info;
	WINDOW				*arena;
	WINDOW				*ply1;
	WINDOW				*ply2;
	WINDOW				*ply3;
	WINDOW				*ply4;
	WINDOW				*finish;
	struct s_slot		slots[MEM_SIZE + 1];
	size_t				p_posy[4];
	size_t				p_posx;
	char				p_name[4][23];
	char				state;
	char				speed;
	bool				active;
}						t_win;

typedef struct			s_op
{
	char				*ope;
	unsigned int		n_arg;
	int					type[MAX_ARGS_NUMBER];
	char				index;
	int					cycle;
	char				*desc;
	bool				isopc;
	bool				size_dir;
}						t_op;

typedef struct			s_process
{
	int					reg_tab[REG_NUMBER];
	int					args_type[MAX_ARGS_NUMBER];
	int					args_value[MAX_ARGS_NUMBER];
	int					args_size[MAX_ARGS_NUMBER];
	int					carry;
	int					live;
	int					player;
	int					sleeper;
	unsigned int		id;
	unsigned int		pc;
	unsigned char		opcode;
}						t_process;

typedef struct			s_player
{
	unsigned char		*origin_code;
	t_header			header;
	unsigned int		lives;
	unsigned int		last_live;
	int					start_position;
	int					padding;
	int					number;
}						t_player;

typedef struct			s_env
{
	unsigned char		arena[MEM_SIZE];
	t_player			players[MAX_PLAYERS];
	t_list				*progs;
	t_win				visu;
	unsigned int		cycles;
	unsigned int		cycle_to_die;
	unsigned int		last_cycle_to_die;
	unsigned int		checks;
	unsigned int		dump;
	unsigned int		dump_repeat;
	unsigned int		nbr_live;
	unsigned int		nbr_players;
	unsigned int		nbr_progs;
	unsigned int		nbr_args;
	unsigned int		id;
	unsigned int		options;
	int					player_number;
	int					exception;
}						t_env;

extern					t_op	g_op_tab[17];

extern void				prepare_game(t_env *env, int ac, char *av[]);
extern int				corewar_usage(void);
extern t_env			initialize_env(void);
extern int				read_params(t_env *env, int ac, char *av[]);
extern void				set_players(t_env *env, unsigned int place);
extern int				read_champions(t_env *env, char *arg);
extern void				initialize_players(t_env *env);
extern t_list			*create_player(int player_nbr, t_env *env);
extern void				get_options(t_env *env, char **av, int ac, int found);
extern int				detect_champion(char *str);
extern int				check_duplicate(t_env *env);
extern void				champ_name(char **av, int ac, t_env *env, int i);
extern void				dump_timing(char **av, int ac, t_env *env, int *i);
extern void				dump_repeat(char **av, int ac, t_env *env, int *i);
extern void				verbosity(char **av, int ac, t_env *env, int *i);

extern void				add_process(t_process *process_father,
							int pc, t_env *env);
extern void				ft_live(t_process *process, t_env *env);
extern void				ft_ld(t_process *process, t_env *env);
extern void				ft_st(t_process *process, t_env *env);
extern void				ft_add_op(t_process *process, t_env *env);
extern void				ft_sub_op(t_process *process, t_env *env);
extern void				ft_and_op(t_process *process, t_env *env);
extern void				ft_or_op(t_process *process, t_env *env);
extern void				ft_xor_op(t_process *process, t_env *env);
extern void				ft_zjmp(t_process *process, t_env *env);
extern void				ft_ldi_op(t_process *process, t_env *env);
extern void				ft_sti_op(t_process *process, t_env *env);
extern void				ft_fork_op(t_process *process, t_env *env);
extern void				ft_lld_op(t_process *process, t_env *env);
extern void				ft_lldi_op(t_process *process, t_env *env);
extern void				ft_lfork_op(t_process *process, t_env *env);
extern void				ft_aff_op(t_process *process, t_env *env);

extern void				create_arena(t_env *env);
extern void				display_arena(t_env *env);
extern char				*traduction(unsigned char n);
extern void				move_process(t_process *process, t_env *env);
extern void				ft_write_arena(unsigned char *line, unsigned int index,
							unsigned int octet, unsigned int number);
extern unsigned int		ft_read_arena(unsigned char *line, unsigned int index,
							unsigned int octet);
extern void				introduce_players(t_env *env);

extern void				start_game(t_env *env, unsigned int active_cycle);
extern int				ft_check_process_life(t_list **curent,
							t_list **previous);
extern unsigned int		ft_check_all_process_life(t_env *env);
extern void				call_all_process(t_env *env);
extern void				call_process(t_process *process, t_env *env);

extern void				exec_instruction(t_process *process, t_env *env);
extern int				scan_opcode(t_process *process, t_env *env);
extern t_process		*scan_coding_param(t_process *process, t_env *env);
extern int				check_coding_param(int *tab, unsigned char opcode);
extern int				cast_short(int value);
extern int				get_instruction_value(t_process *process, t_env *env);
extern void				set_size(t_process *process);

extern unsigned int		ft_getbinary_numb(unsigned char *line,
							unsigned int index, unsigned int octet);
extern void				show_all_process(t_env *env);
extern int				ft_return_value(t_env *env, t_process *process, int i);
extern int				check_last_process(t_env *env, t_process *process);
extern int				ft_read_errors(t_env *env, unsigned char *line, int fd,
						unsigned char opt);
extern void				ft_sleep(t_env *env);
extern int				ope_size_type(int type_code, int opcode);

extern void				v_main(t_env *env);
extern void				vinit_slot(t_win *env);
extern void				v_arena(t_env *env);
extern void				v_process(t_env *env);
extern void				v_info(t_env *env);
extern void				v_name(t_env *env);
extern void				v_store(size_t pos, t_env *env, int ply, size_t len);
extern void				v_clean(t_env *env);
extern void				v_pcolor(t_env *env);
extern void				v_key(t_env *env);
extern void				v_rprint(t_env *env);
extern void				v_pause(t_env *env);
extern void				p_player(t_env *env);
extern void				p_info(t_env *env, bool end);
extern void				p_finish(t_env *env);
extern void				p_arena(t_env *env, int n, char *s);

#endif
