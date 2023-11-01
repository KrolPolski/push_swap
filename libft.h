/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:39:46 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/01 11:10:35 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
unsigned char	*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(unsigned char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(unsigned char *s, int fd);
char			**ft_split(unsigned char const *s, char c);
unsigned char	*ft_strchr(unsigned const char *s, int c);
unsigned char	*ft_strdup(const unsigned char *s1);
unsigned char	*ft_strjoin(unsigned char const *s1, unsigned char const *s2);
size_t			ft_strlcat(unsigned char *dst, const unsigned char *src,
					size_t dstsize);
size_t			ft_strlcpy(unsigned char *dst, const unsigned char *src,
					size_t dstsize);
size_t			ft_strlen(const unsigned char *s);
char			*ft_strmapi(unsigned char const *s,
					char (*f)(unsigned int, char));
int				ft_strncmp(const unsigned char *s1,
					const unsigned char *s2, size_t n);
char			*ft_strnstr(const unsigned char *haystack,
					const unsigned char *needle, size_t len);
unsigned char	*ft_strrchr(const unsigned char *s, int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
unsigned char	*ft_strtrim(unsigned char const *s1, unsigned char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			ft_tolower(char c);
char			ft_toupper(char c);
#endif
