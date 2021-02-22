/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:24:02 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/26 19:18:20 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_darken(int *color, float *walldist)
{
	static float	dark;

	dark = *walldist * 0.24f + 1;
	return ((int)((*color >> 16 & 0xFF) / \
	dark) << 16 | (int)((*color >> 8 & 0xFF) / \
	dark) << 8 | (int)((*color & 0xFF) / dark));
}
