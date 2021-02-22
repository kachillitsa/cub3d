/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:57:07 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite_b(float *height, int *y, int *stop)
{
	*height = g_txtr.en_anim[0][g_sprite\
		[g_sumup.isprite_n].en_anim_i].height * \
		g_sprite[g_sumup.isprite_n].fsprite_up;
	*y = g_proj.scr_hght05 + g_ur.iur_z;
	*stop = *stop + g_sprite[g_sumup.isprite_n].fsprite_h;
	if (*stop > g_proj.scr_hght)
		*stop = g_proj.scr_hght;
	if (*stop > g_sprite[g_sumup.isprite_n].isprite_y2)
		*stop = g_sprite[g_sumup.isprite_n].isprite_y2;
}

void	ft_sprite_c(int *y, int *col_pix, \
	float *height, float *fdist_to_wall)
{
	*col_pix = \
	g_txtr.en_anim[0][g_sprite[g_sumup.isprite_n].\
	en_anim_i].data[(int)*height * \
		g_txtr.en_anim[0][g_sprite[g_sumup.isprite_n].\
		en_anim_i].width + (int)g_sprite[g_sumup.\
		isprite_n].fe_count_w];
	if (*col_pix > 100)
	{
		g_proj.win_buf.data[*y * g_proj.scr_wth + \
			g_sumup.iray_x] = ft_darken(col_pix, \
			fdist_to_wall);
		if (g_sumup.ishot > 0 && *y == g_proj.scr_hght05 && \
			g_sumup.iray_x == g_proj.scr_wth05)
			g_sprite[g_sumup.isprite_n].iheart -= 5;
	}
	*height += g_sprite[g_sumup.isprite_n].fsprite_txtrh_step;
	*y = *y + 1;
}

void	ft_sprite_d(int *col_pix, int *y, \
	float *height, float *fdist_to_wall)
{
	if (*y < g_sprite[g_sumup.isprite_n].isprite_y2)
	{
		*col_pix = g_txtr.en_anim[0][g_sprite[g_sumup.isprite_n].\
			en_anim_i].data[(int)*height * g_txtr.en_anim[0][g_sprite\
			[g_sumup.isprite_n].en_anim_i].width + \
			(int)g_sprite[g_sumup.isprite_n].fe_count_w];
		if (*col_pix > 100)
		{
			g_proj.win_buf.data[*y * g_proj.scr_wth \
				+ g_sumup.iray_x] = ft_darken(col_pix, \
				fdist_to_wall);
			if (g_sumup.ishot > 0 && *y == g_proj.\
				scr_hght05 && g_sumup.iray_x == g_proj.scr_wth05)
				g_sprite[g_sumup.isprite_n].iheart -= 20;
			if (*y < g_sumup.ceil_dn[g_sumup.iray_x])
				g_sumup.ceil_dn[g_sumup.iray_x] = *y;
		}
	}
}

void	ft_sprite2(int *y, float *fdist_to_wall)
{
	static int		stop;
	static int		col_pix;
	static float	height;

	if (g_sumup.iray_x >= 0)
	{
		height = g_txtr.en_anim[0][g_sprite[g_sumup.isprite_n].\
			en_anim_i].height * g_sprite[g_sumup.isprite_n].fsprite_up;
		*y = g_proj.scr_hght05 + g_ur.iur_z;
		if ((stop = g_proj.scr_hght05 - \
				g_sprite[g_sumup.isprite_n].fsprite_h * \
				g_sprite[g_sumup.isprite_n].fsprite_up + g_ur.iur_z) < 0)
			stop = 0;
		while (*y > stop)
		{
			ft_sprite_d(&col_pix, y, \
				&height, fdist_to_wall);
			height -= g_sprite[g_sumup.isprite_n].fsprite_txtrh_step;
			*y = *y - 1;
		}
		ft_sprite_b(&height, y, &stop);
		while (*y < stop)
			ft_sprite_c(y, &col_pix, &height, \
				fdist_to_wall);
	}
}
