/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base_upp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:19:59 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 14:03:25 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert(unsigned long long n, \
							const unsigned base, \
							char *str, size_t i)
{
	int			res;
	char		*bstr;

	res = 0;
	bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (base == 1 && (i <= ft_nbrlenbase_ull(n, base)))
	{
		str[i] = '1';
		i++;
		if (i == ft_nbrlenbase_ull(n, base) - 1)
			return (str);
	}
	if (n > 0)
	{
		res = n % base;
		str[i] = bstr[res];
		i++;
		ft_convert(n / base, base, str, i);
	}
	return (str);
}

char			*ft_ulltoa_base_upp(unsigned long long nb, const unsigned base)
{
	int			len;
	char		*str;

	len = 0;
	if (base <= 0)
	{
		return (NULL);
	}
	if (nb == 0)
	{
		return (ft_strdup("0"));
	}
	len = ft_nbrlenbase_ull(nb, base);
	str = (char *)ft_strnew(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		str = ft_convert(nb, base, str, 0);
		str[len] = '\0';
		str = ft_strrev(str, 0);
	}
	return (str);
}
