/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:13:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/20 17:40:21 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_l(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * ft_l(s1) + 1)))
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	if (s[i] == '\0' && c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_l(s1) + ft_l(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoinfree(char **s1, char **s2, int key)
{
	char	*res;

	if (s1 == NULL || s2 == NULL || key > 4 || key < 0)
		return (NULL);
	res = ft_strjoin_gnl(*s1, *s2);
	if ((key % 2) == 1)
	{
		free(*s1);
		*s1 = NULL;
		s1 = NULL;
	}
	if (key > 1)
	{
		free(*s2);
		*s2 = NULL;
		s2 = NULL;
	}
	return (res);
}
