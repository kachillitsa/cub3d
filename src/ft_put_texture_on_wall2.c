/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_texture_on_wall2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:38:00 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_textwall2_2(float *fray_ang, \
	t_obj *obj, t_temp *temp, int *n)
{
	temp->iceiling_y = g_proj.scr_hght05 - g_proj.scr_hght / \
		(obj[*n].fdist * cosf(*fray_ang - g_ur.ur_va));
	temp->ifloor_y = g_proj.scr_hght - temp->iceiling_y;
	temp->iceiling_y = temp->iceiling_y + temp->iceiling_y - \
		temp->ifloor_y + g_ur.iur_z;
	temp->ifloor_y += g_ur.iur_z;
}

void	ft_set_colors(int idraw_y, t_obj *obj, t_temp *temp, int *n)
{
	static int		col_pix;
	static int		crosswall;

	crosswall = obj[*n].ctype - '0';
	while (idraw_y >= temp->iceiling_y)
	{
		col_pix = g_txtr.txtr_wall[crosswall].data[(int)temp->fcount_h * \
			g_txtr.txtr_wall[crosswall].width + temp->icount_w];
		if (col_pix == 0)
			break ;
		g_proj.win_buf.data[idraw_y * g_proj.scr_wth + \
			g_sumup.iray_x] = ft_darken(&col_pix, &obj[*n].fdist);
		temp->fcount_h -= temp->ftxtr_hstep;
		idraw_y--;
	}
	g_sumup.ceil_dn[g_sumup.iray_x] = idraw_y;
}

void	ft_put_texture_on_wall2(float *fray_ang, int *crosswall, \
	t_obj *obj, int *n)
{
	static t_temp	temp;

	ft_textwall2_2(fray_ang, obj, &temp, n);
	temp.ftxtr_hstep = (float)g_txtr.txtr_wall[*crosswall].height / \
		(temp.ifloor_y - temp.iceiling_y);
	if (temp.iceiling_y <= g_sumup.ceil_dn[g_sumup.iray_x])
	{
		if (temp.iceiling_y < 0)
			temp.iceiling_y = 0;
		temp.fcount_h = g_txtr.txtr_wall[*crosswall].height;
		if (temp.ifloor_y > g_sumup.ceil_dn[g_sumup.iray_x])
		{
			temp.fcount_h -= temp.ftxtr_hstep * (temp.ifloor_y - \
				g_sumup.ceil_dn[g_sumup.iray_x]);
			temp.ifloor_y = g_sumup.ceil_dn[g_sumup.iray_x];
		}
		if ((obj[*n].f_xx - g_math.fstep_check) > (obj[*n].i_xx) && \
			(obj[*n].f_xx + g_math.fstep_check) < (obj[*n].i_xx + 1))
			temp.icount_w = (obj[*n].f_xx - (int)obj[*n].f_xx) * \
				g_txtr.txtr_wall[*crosswall].width;
		else
			temp.icount_w = (obj[*n].f_yy - (int)obj[*n].f_yy) * \
				g_txtr.txtr_wall[*crosswall].width;
		ft_set_colors(temp.ifloor_y, obj, &temp, n);
	}
}
