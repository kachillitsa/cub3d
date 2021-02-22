/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_texture_on_wall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:36:51 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 18:55:37 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_textwall_2(t_obj *obj, int *n)
{
	while (*n >= 0)
	{
		if (obj[*n].ctype >= 'a')
		{
			g_sumup.isprite_n = obj[*n].ctype - 'a';
			g_sumup.f_xx = obj[*n].f_xx;
			g_sumup.f_yy = obj[*n].f_yy;
			ft_sprite(&obj[*n].fdist);
		}
		*n = *n - 1;
	}
}

void	ft_put_texture_on_wall(float *fray_ang, t_obj *obj, int *i)
{
	static int	crosswall;
	static int	n;

	n = 0;
	while (n <= *i)
	{
		if (obj[n].ctype < 'a')
		{
			crosswall = obj[n].ctype - '0';
			ft_put_texture_on_wall2(fray_ang, &crosswall, obj, &n);
		}
		else
			g_sprite[obj[n].ctype - 'a'].isprite_y2 = \
				g_sumup.ceil_dn[g_sumup.iray_x];
		n++;
	}
	n = *i;
	ft_textwall_2(obj, &n);
}
