/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:25:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:42:11 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_validate(void)
{
	t_val	val;

	ft_set_all_zero(&val);
	if (ft_definetype(&val) == -1)
	{
		write(2, "Error:\na .cub mistake\n", 23);
		return (-1);
	}
	if (ft_check_position(&val) == -1)
	{
		write(2, "Error:\nchange user position\n", 29);
		return (-1);
	}
	ft_resolution(&g_proj.scr_wth, &g_proj.scr_hght);
	return (0);
}
