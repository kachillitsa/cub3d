/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:04:28 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite2b(float *fdist_to_wall)
{
	if (g_sprite[g_sumup.isprite_n].ifirst_rayx == -401)
	{
		g_sprite[g_sumup.isprite_n].fe_count_w = 0;
		g_sprite[g_sumup.isprite_n].fsprite_width = g_proj.scr_hght / \
			*fdist_to_wall / g_sprite[g_sumup.isprite_n].fsprite_wzero;
		g_sprite[g_sumup.isprite_n].fsprite_stepw = \
		g_txtr.en_anim[0][g_sprite[g_sumup.isprite_n].en_anim_i].width / \
			g_sprite[g_sumup.isprite_n].fsprite_width;
		g_sprite[g_sumup.isprite_n].fsprite_h = g_proj.scr_hght / \
			*fdist_to_wall * g_sprite[g_sumup.isprite_n].fsprite_tall;
		g_sprite[g_sumup.isprite_n].fsprite_txtrh_step = \
			(float)g_txtr.en_anim[0][g_sprite\
			[g_sumup.isprite_n].en_anim_i].height / \
			g_sprite[g_sumup.isprite_n].fsprite_h;
	}
}

void	ft_sprite(float *fdist_to_wall)
{
	static int		x;
	static int		y;

	x = (g_sumup.f_xx - (int)g_sumup.f_xx) * 30;
	y = (g_sumup.f_yy - (int)g_sumup.f_yy) * 30;
	if (g_sumup.sprite[g_sumup.isprite_n][y][x] == '+')
	{
		ft_sprite2b(fdist_to_wall);
		if (g_sumup.iray_x > g_sprite[g_sumup.isprite_n].ifirst_rayx)
		{
			g_sprite[g_sumup.isprite_n].fe_count_w += \
				g_sprite[g_sumup.isprite_n].fsprite_stepw;
			ft_sprite2(&y, fdist_to_wall);
			g_sprite[g_sumup.isprite_n].ifirst_rayx = g_sumup.iray_x;
		}
	}
}
