/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_all_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:30:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:44:21 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	ft_set_all_zero(t_val *val)
{
	val->scr_wdth = 0;
	val->scr_hght = 0;
	val->col_ceiling = 0;
	val->col_floor = 0;
	val->ishere_n = 0;
	val->ishere_so = 0;
	val->ishere_w = 0;
	val->ishere_e = 0;
	val->ishere_s = 0;
	val->ishere_f = 0;
	val->ishere_c = 0;
	val->ishere_r = 0;
	val->m_trashl = 0;
	val->trashl_m = 0;
	val->m_e = 0;
	val->m_n = 0;
	val->m_s = 0;
	val->m_w = 0;
	g_adr.adr_no = 0;
	g_adr.adr_so = 0;
	g_adr.adr_we = 0;
	g_adr.adr_ea = 0;
	g_adr.adr_s = 0;
	g_sumup.sp_num = 0;
}
