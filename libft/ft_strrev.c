/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:19:43 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 14:08:39 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *a, char *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strrev(char *str, int start)
{
	int i;
	int len;

	i = start;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		ft_swap(&str[i], &str[len]);
		i++;
		len--;
	}
	return (str);
}
