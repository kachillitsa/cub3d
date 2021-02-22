/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_who_is_absent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:44:40 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 16:09:04 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_who_is_absent(t_val *val)
{
	if (val->ishere_r != 1 || val->ishere_n != 1 \
	|| val->ishere_e != 1 || val->ishere_s != 1 \
	|| val->ishere_so != 1 || val->ishere_w != 1 \
	|| val->ishere_f != 1 || val->ishere_c != 1)
		return (-1);
	else
		return (0);
}
