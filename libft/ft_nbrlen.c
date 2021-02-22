/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:18:09 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 14:13:45 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen(int nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0 && base == 10)
		len += 1;
	while (nb)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}
