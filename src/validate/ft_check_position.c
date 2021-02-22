/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:16:59 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:10:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_check_position(t_val *val)
{
	if (val->m_e == 1 && val->m_w == 0 \
	&& val->m_s == 0 && val->m_n == 0)
		return (0);
	else if (val->m_w == 1 && val->m_e == 0 \
	&& val->m_s == 0 && val->m_n == 0)
		return (0);
	else if (val->m_s == 1 && val->m_w == 0 \
	&& val->m_e == 0 && val->m_n == 0)
		return (0);
	else if (val->m_n == 1 && val->m_w == 0 \
	&& val->m_s == 0 && val->m_e == 0)
		return (0);
	else
		return (-1);
}
