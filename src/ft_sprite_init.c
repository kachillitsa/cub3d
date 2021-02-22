/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:32:37 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite_init_one(int i)
{
	g_txtr.en_anim[i][0].scale = 1;
	g_sumup.sprite[i] = malloc(sizeof(char*) * 31);
	g_sumup.sprite[i][0] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][1] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][2] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][3] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][4] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][5] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][6] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][7] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][8] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][9] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][10] = ft_strdup("-------------+++++-----------");
	g_sumup.sprite[i][11] = ft_strdup("-------------+++++-----------");
	g_sumup.sprite[i][12] = ft_strdup("------------+++++++----------");
	g_sumup.sprite[i][13] = ft_strdup("-----------+++++++++---------");
	g_sumup.sprite[i][14] = ft_strdup("-----------+++++++++---------");
}

void	ft_sprite_init_two(int i)
{
	g_sumup.sprite[i][15] = ft_strdup("------------+++++++----------");
	g_sumup.sprite[i][16] = ft_strdup("------------+++++++----------");
	g_sumup.sprite[i][17] = ft_strdup("------------+++++++----------");
	g_sumup.sprite[i][18] = ft_strdup("-------------+++++-----------");
	g_sumup.sprite[i][19] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][20] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][21] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][22] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][23] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][24] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][25] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][26] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][27] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][28] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][29] = ft_strdup("-----------------------------");
	g_sumup.sprite[i][30] = ft_strdup("-----------------------------");
}

void	ft_sprite_init_three(int *i)
{
	g_sprite[*i].fsprite_wzero = (float)g_proj.scr_hght / \
		(float)g_proj.scr_wth * 3.25f;
	g_sprite[*i].fsprite_up = 0.1f;
	g_sprite[*i].fsprite_dn = 1.0f - g_sprite[*i].fsprite_up;
	g_sprite[*i].fsprite_tall = 1.1f;
	g_sprite[*i].en_anim_i = 0;
	g_sprite[*i].ifirst_rayx = -401;
	ft_sprite_init_one(*i);
	ft_sprite_init_two(*i);
	*i = *i + 1;
}

void	ft_sprite_init(void)
{
	int i;

	g_sprite = malloc(sizeof(t_sprite) * g_sumup.sp_num);
	g_sumup.sprite = malloc(sizeof(char**) * g_sumup.sp_num);
	g_txtr.en_anim = malloc(sizeof(t_image*) * g_sumup.sp_num);
	i = 0;
	while (i < g_sumup.sp_num)
	{
		g_txtr.en_anim[i] = malloc(sizeof(t_image) * 16);
		if ((g_txtr.en_anim[i][0].ptr = mlx_xpm_file_to_image(g_proj.mlx, \
			g_adr.adr_s, &g_txtr.en_anim[i][0].width, \
			&g_txtr.en_anim[i][0].height)) == NULL)
		{
			write(2, "Error:\nno texture\n", 19);
			ft_finish(2);
			exit(0);
		}
		g_txtr.en_anim[i][0].data = (int *)mlx_get_data_addr(g_txtr.\
			en_anim[i][0].ptr, &g_txtr.en_anim[i][0].bpp, &g_txtr.\
			en_anim[i][0].size_line, &g_txtr.en_anim[i][0].b_ord);
		ft_sprite_init_three(&i);
	}
}
