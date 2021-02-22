/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:18:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 14:11:08 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlenbase(long long nb, int base)
{
	size_t len;

	len = 1;
	if (nb < 0)
		len++;
	if (base == 1)
	{
		if (nb < 0)
			nb = nb * -1;
		return ((size_t)nb + len);
	}
	while (nb / base != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}
