/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:51:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rays(void)
{
	g_ur.fur_z0 = -0.6f;
	g_ur.fur_z2 = 1.0f;
	g_ur.speed = 0.04f;
	g_ur.keys_on = K_NONE;
	g_ur.iur_z = 0;
	g_math.ffov = 3.14159 / 3.2;
	g_math.ffov_vert = g_math.ffov;
	g_math.ffloor_ang0 = PI / 2.0f - g_math.ffov_vert / 2.0f;
	g_math.ffov05 = g_math.ffov / 2.0f;
	g_math.fray_as = 1.0f / (float)g_proj.scr_wth * g_math.ffov;
	g_math.fray_as2 = g_math.fray_as * 2;
	g_math.ffloor_as = 1.0f / (float)(g_proj.scr_hght) \
		* g_math.ffov_vert;
	g_math.ffloor_as2 = g_math.ffloor_as * 2;
	g_math.fstep_check = 0.01f;
	g_sumup.ceil_x = -g_txtr.txtr_ceil.width / 2;
}
