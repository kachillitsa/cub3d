/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase_ull.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:18:24 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 14:11:35 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlenbase_ull(unsigned long long nb, int base)
{
	size_t len;

	len = 1;
	if (base == 1)
		return ((size_t)nb + len);
	while (nb / base != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}
