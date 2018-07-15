/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:13:02 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/23 16:28:33 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void			*ke_memset(void *b, int c, size_t len);
void			ke_bzero(void *s, size_t n);
void			*ke_memcpy(void *dst, const void *src, size_t n);
void			*ke_memccpy(void *dst, const void *src, int c, size_t n);
void			*ke_memmove(void *dst, const void *src, size_t len);
void			*ke_memchr(const void *s, int c, size_t n);
int				ke_memcmp(const void *s1, const void *s2, size_t n);
void			ke_nothing(void);
unsigned int	ke_strlen(const char *str);
int				ke_str2len(char **arr);
int				ke_strclen(const char *str, char c);
int				ke_strnlen(const char *str, char c);
char			*ke_strdup(const char *src);
char			*ke_strndup(const char *src, unsigned int size);
char			*ke_strcpy(char *dest, const char *src);
char			*ke_strncpy(char *dest, const char *src, size_t len);
char			*ke_strcat(char *dest, const char *src);
char			*ke_strncat(char *dest, const char *src, size_t len);
size_t			ke_strlcat(char *dest, const char *src, size_t len);
char			*ke_strchr(const char *s, int c);
char			*ke_strrchr(const char *s, int c);
char			*ke_strstr(const char *big, const char *little);
char			*ke_strnstr(const char *big, const char *little, size_t len);
int				ke_strcmp(const char *s1, const char *s2);
int				ke_strncmp(const char *s1, const char *s2, size_t n);
int				ke_atoi(const char *str);
int				ke_isalpha(int c);
int				ke_isdigit(int c);
int				ke_isalnum(int c);
int				ke_isascii(int c);
int				ke_isprint(int c);
int				ke_tolower(int c);
int				ke_toupper(int c);
void			*ke_memalloc(size_t size);
void			ke_memdel(void **ap);
char			*ke_strnew(size_t size);
void			ke_strdel(char **as);
void			ke_free_str2(char **arr);
void			ke_strclr(char *s);
void			ke_striter(char *s, void (*f)(char *));
void			ke_striteri(char *s, void (*f)(unsigned int, char *));
char			*ke_strmap(char const *s, char (*f)(char));
char			*ke_strmapi(char const *s, char (*f)(unsigned int, char));
int				ke_strequ(char const *s1, char const *s2);
int				ke_strnequ(char const *s1, char const *s2, size_t n);
char			*ke_strsub(char const *s, unsigned int start, size_t len);
char			*ke_strjoin(char const *s1, char const *s2);
char			*ke_strjoin_free(char *s1, char *s2);
char			*ke_strtrim(char const *s);
char			**ke_strsplit(char const *s, char c);
char			*ke_itoa(int n);
void			ke_putchar(char c);
void			ke_putstr(char const *s);
void			ke_putendl(char const *s);
void			ke_putnbr(int n);
void			ke_putunbr_fd(unsigned int c, int fd);
void			ke_putchar_fd(char c, int fd);
void			ke_putuchar_fd(unsigned char c, int fd);
void			ke_putstr_fd(char const *s, int fd);
void			ke_putendl_fd(char const *s, int fd);
void			ke_putnbr_fd(int n, int fd);
char			*ke_itoa_base(int n, int base);
void			ke_swap(int *a, int *b);
#endif
