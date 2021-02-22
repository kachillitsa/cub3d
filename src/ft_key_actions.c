/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:33 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 17:37:45 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_up_dn(void)
{
	if ((g_ur.keys_on & K_ON_W) != 0)
	{
		g_ur.ur_y -= cosf(g_ur.ur_va) * g_ur.speed;
		g_ur.ur_x -= sinf(g_ur.ur_va) * g_ur.speed;
		if (g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != '0' \
			&& g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != ' ')
		{
			g_ur.ur_y += cosf(g_ur.ur_va) * g_ur.speed * 2;
			g_ur.ur_x += sinf(g_ur.ur_va) * g_ur.speed * 2;
		}
	}
	else if ((g_ur.keys_on & K_ON_S) != 0)
	{
		g_ur.ur_y += cosf(g_ur.ur_va) * g_ur.speed;
		g_ur.ur_x += sinf(g_ur.ur_va) * g_ur.speed;
		if (g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != '0' \
			&& g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != ' ')
		{
			g_ur.ur_y -= cosf(g_ur.ur_va) * g_ur.speed * 2;
			g_ur.ur_x -= sinf(g_ur.ur_va) * g_ur.speed * 2;
		}
	}
}

void	ft_key_move(void)
{
	if ((g_ur.keys_on & K_ON_A) != 0)
	{
		g_ur.ur_y += cosf(g_ur.ur_va - 1.7f) * g_ur.speed / 1.5f;
		g_ur.ur_x += sinf(g_ur.ur_va - 1.7f) * g_ur.speed / 1.5f;
		if (g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != '0' \
			&& g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != ' ')
		{
			g_ur.ur_y -= cosf(g_ur.ur_va - 1.7f) * g_ur.speed * 2;
			g_ur.ur_x -= sinf(g_ur.ur_va - 1.7f) * g_ur.speed * 2;
		}
	}
	else if ((g_ur.keys_on & K_ON_D) != 0)
	{
		g_ur.ur_y -= cosf(g_ur.ur_va - 1.7f) * g_ur.speed / 1.5f;
		g_ur.ur_x -= sinf(g_ur.ur_va - 1.7f) * g_ur.speed / 1.5f;
		if (g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != '0' \
			&& g_sumup.map[(int)g_ur.ur_y][(int)g_ur.ur_x] != ' ')
		{
			g_ur.ur_y += cosf(g_ur.ur_va - 1.7f) * g_ur.speed * 2;
			g_ur.ur_x += sinf(g_ur.ur_va - 1.7f) * g_ur.speed * 2;
		}
	}
	ft_key_up_dn();
}

void	ft_key_actions(void)
{
	if ((g_ur.keys_on & K_ON_S) != 0 || \
	(g_ur.keys_on & K_ON_W) != 0 || \
	(g_ur.keys_on & K_ON_D) != 0 || (g_ur.keys_on & K_ON_A) != 0)
		ft_key_move();
	if ((g_ur.keys_on & K_ON_LT) != 0)
	{
		g_ur.ur_va += 0.08f;
		g_sumup.ceil_x = g_sumup.ceil_x + 0.08f * 200;
		if (g_sumup.ceil_x > 0)
			g_sumup.ceil_x = -g_txtr.txtr_ceil.width / 2;
		else if (g_sumup.ceil_x < -g_txtr.txtr_ceil.width / 2)
			g_sumup.ceil_x = 0;
	}
	else if ((g_ur.keys_on & K_ON_RT) != 0)
	{
		g_ur.ur_va -= 0.08f;
		g_sumup.ceil_x = g_sumup.ceil_x - 0.08f * 200;
		if (g_sumup.ceil_x > 0)
			g_sumup.ceil_x = -g_txtr.txtr_ceil.width / 2;
		else if (g_sumup.ceil_x < -g_txtr.txtr_ceil.width / 2)
			g_sumup.ceil_x = 0;
	}
}
