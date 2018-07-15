/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:28:36 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/05 21:18:28 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "limits.h"
# include "./lo_get_next_line.h"
# include "../../ft_printf/includes/ft_printf.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

char				*lo_base_conv(char *str, int base_src, int base_dest);
char				*lo_itoa(int n);
char				*lo_itoa_base(long long n, int base);
char				*lo_itoa_base_unsigned(unsigned long long n, int base);

t_list				*lo_create_lst(int size, int content_size);
int					lo_lst_add(t_list **alst, t_list *mew);
int					lo_lst_add_end(t_list **lst, t_list *mew);
int					lo_lst_advance(t_list **head, int advance);
void				lo_lst_cnttdel(void **content);
void				lo_lst_del_all(t_list **lst);
t_list				*lo_lst_del_last(t_list **lst);
void				lo_lst_del_one(t_list **lst, int position);
t_list				*lo_lst_getend(t_list *lst);
t_list				*lo_lst_int_copy(t_list *lst);
t_list				*lo_lsti_map(t_list *lst, t_list *(*f)(t_list *elem));
void				lo_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*lo_lst_last(t_list *lst);
t_list				*lo_lst_new(size_t content_size);
t_list				*lo_lst_push_params(int argc, char **argv);
void				lo_lst_reset(t_list **head);
t_list				*lo_lst_reverse(t_list *lst);
int					lo_lst_size(t_list *lst);
int					lo_lst_stepback(t_list **head, int stepback);

void				lo_putchar(char c);
void				lo_putchar_fd(char c, int fd);
void				lo_putendl(char const *s);
void				lo_putendl_fd(char const *s, int fd);
void				lo_putlong_unsigned(unsigned long long n);
void				lo_putlong(long long n);
void				lo_putnbr(int n);
void				lo_putnbrn(int n);
void				lo_putnbr_abs(long long int n);
void				lo_putnbr_fd(int n, int fd);
void				lo_putstr(const char *s);
void				lo_putstr_fd(const char *s, int fd);
void				lo_putwchar(wchar_t wchar);
void				lo_putwstr(wchar_t *wstr);

void				lo_fill_str_c(char *str, char c);
int					lo_memcmp(const void *s1, const void *s2, size_t n);
void				*lo_memcpy(void *dst, const void *src, size_t n);
void				*lo_memccpy(void *dst, const void *src, int c, size_t n);
void				*lo_memchr(void *s, int c, size_t n);
void				*lo_memmove(void *dst, const void *src, size_t len);
void				*lo_memset(void *b, int c, size_t len);
char				*lo_strcat(char *s1, const char *s2);
char				*lo_strchr(char *s, int c);
void				lo_strclr(char *s);
int					lo_strcmp(const char *s1, const char *s2);
int					lo_strcmp_c(const char *s1, const char *s2, char c);
int					lo_strcmp_n(const char *s1, const char *s2, int size);
char				*lo_strcpy(char *dest, const char *src);
int					lo_strequ(const char *s1, const char *s2);
void				lo_strdel(char **as);
void				lo_strdel_two(char **as, char **asbis);
char				*lo_strdup(const char *s1);
char				*lo_strdup_free(const char *s1, char **out);
int					lo_strhexa_int(char *str);
char				*lo_strjoin(const char *s1, const char *s2);
char				*lo_strjoin_free(char *s1, char *s2, char **out);
size_t				lo_strlcat(char *dst, const char *src, size_t size);
int					lo_strlen(const char *s);
int					lo_strlen_c(char *str, char c);
int					lo_strlen_to(const char *s, char c);
char				*lo_strncat(char *s1, const char *s2, size_t n);
int					lo_strncmp(const char *s1, const char *s2, size_t n);
char				*lo_strncpy(char *dest, const char *src, size_t len);
int					lo_strnequ(const char *s1, const char *s2, size_t n);
char				*lo_strnstr(char *haystack,
					const char*needle, size_t len);
char				*lo_strrchr(char *s, int c);
char				*lo_str_replace(char *str, char old, char mew);
int					lo_strsearch(char *str, char c);
char				**lo_strsplit(const char *s, char c);
char				*lo_strstr(char *haystack, const char *needle);
int					lo_strstr_int(const char *haystack, const char *needle);
char				*lo_strsub(const char *s, unsigned int start, size_t len);
char				*lo_strsub_free(const char *s, unsigned int start,
					size_t len, char **out);
char				*lo_strtrim_c(char const *s, char c);
void				lo_swap_str(char *a, char *b);
char				*lo_toupper_str(char *str);
char				*lo_strtrim(char const *s);
unsigned char		*lo_unsigned_strdup(char *s1);

int					lo_abs(int i);
int					lo_atoi(const char *str);
unsigned long long	lo_atoi_unsignedlong(const char *str);
int					lo_int_length(long long int i);
int					lo_isalnum(int c);
int					lo_isalpha(int c);
int					lo_isascii(int c);
int					lo_isdigit(int c);
int					lo_is_integer(char *str);
int					lo_is_negative(int n);
int					lo_is_number(char *str);
int					lo_isprint(int c);
int					lo_is_whitespace(char x);
void				lo_print_params(int argc, char **argv);
long long			lo_power(long long n, int power);
int					lo_nbr_of_words(const char *s, char c);
int					*lo_range(int min, int max);
int					lo_recursive_factorial(int nb);
void				lo_sort_params(int argc, char **argv);
int					lo_sqrt(int nb);
void				lo_swap(int *a, int *b);
int					lo_tolower(int c);
int					lo_toupper(int c);
int					lo_word_nbr(const char *s, char c);

void				**lo_2d_array(int width, int lenght, int size_type);
void				lo_bzero(void *s, size_t n);
char				**lo_create_chartab(int size, int sizelittle);
void				lo_free_strtab(char ***tab);
void				*lo_memalloc(size_t size);
void				lo_memdel(void **ap);
void				lo_rchar_tab(char **tab);
void				lo_rint_tab(int **tab, int nbr_of_tab, int lenght);
char				*lo_strnew(size_t size);
char				*lo_strnew_free(size_t size, char **str);

t_list				*lo_old_lstnew(void const *content, size_t content_size);

#endif
