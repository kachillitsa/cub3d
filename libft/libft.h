/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:23:34 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 13:46:23 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int				ft_atoi(const char *str);
void			ft_free(char **line1);
void			ft_free_2(char **line1, char **line2);
void			ft_free_3(char **line1, char **line2, char **line3);
void			ft_free_4(char **line1, char **line2, \
	char **line3, char **line4);
char			*ft_itoa(int n);
char			*ft_itoa_base(signed long long nb, const unsigned int base);
size_t			ft_nbrlen(int nb, int base);
size_t			ft_nbrlenbase(long long nb, int base);
size_t			ft_nbrlenbase_ull(unsigned long long nb, int base);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_slltoa_base(signed long long nb, const unsigned int base);
char			*ft_strchr(const char *s, int cchar);
int				ft_strcmp(const char *string1, const char *string2);
char			*ft_strdup(const char *str);
int				ft_strjoin_f(const char *s1, const char *s2, char **dest);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnewfill(size_t size, char c);
char			*ft_strrev(char *str, int start);
char			*ft_ulltoa_base_low(unsigned long long nb, const unsigned base);
char			*ft_ulltoa_base_upp(unsigned long long nb, const unsigned base);

#endif
