/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:17:48 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 04:17:49 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrleni(int nbr)
{
	int len;

	len = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*str;
	int				sign;
	int				size;

	size = ft_nbrleni(n);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	sign = (n < 0 ? 1 : 0);
	nbr = (n < 0 ? -n : n);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
