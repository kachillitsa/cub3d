/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_unpress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:07:01 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 15:06:15 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_unpress(int ikey)
{
	if (ikey == KEY_W)
		g_ur.keys_on -= K_ON_W;
	if (ikey == KEY_S)
		g_ur.keys_on -= K_ON_S;
	if (ikey == KEY_A)
		g_ur.keys_on -= K_ON_A;
	if (ikey == KEY_D)
		g_ur.keys_on -= K_ON_D;
	if (ikey == KEY_LT)
		g_ur.keys_on -= K_ON_LT;
	if (ikey == KEY_RT)
		g_ur.keys_on -= K_ON_RT;
	return (1);
}
