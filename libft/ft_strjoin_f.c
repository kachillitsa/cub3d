/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:19:06 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 14:02:31 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strjoin_f(const char *s1, const char *s2, char **dest)
{
	int		i;
	size_t	len;
	char	*str;

	if (s1 || s2)
	{
		len = (s1) ? ft_strlen(s1) : 0;
		if (!(str = (char*)malloc(sizeof(char) * (len +
							((s2) ? ft_strlen(s2) : 0) + 1))))
			return (-1);
		i = -1;
		if (s1)
			while (s1[++i])
				str[i] = s1[i];
		i = -1;
		if (s2)
			while (s2[++i])
				str[len++] = s2[i];
		str[len] = '\0';
		free(*dest);
		*dest = ft_strdup(str);
		free(str);
		return (1);
	}
	return (-1);
}
