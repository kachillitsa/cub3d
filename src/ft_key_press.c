/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:06:18 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 15:41:38 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int ikey)
{
	if (ikey == KEY_W)
		g_ur.keys_on |= K_ON_W;
	if (ikey == KEY_S)
		g_ur.keys_on |= K_ON_S;
	if (ikey == KEY_A)
		g_ur.keys_on |= K_ON_A;
	if (ikey == KEY_D)
		g_ur.keys_on |= K_ON_D;
	if (ikey == KEY_LT)
		g_ur.keys_on |= K_ON_LT;
	if (ikey == KEY_RT)
		g_ur.keys_on |= K_ON_RT;
	if (ikey == KEY_ESC)
		ft_finish(1);
	return (1);
}
