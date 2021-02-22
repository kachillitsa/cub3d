/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:43:40 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 20:44:21 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_zero_resolution(t_val *val)
{
	if (val->scr_wdth == 0)
		return (-1);
	if (val->scr_hght == 0)
		return (-1);
	else
		return (0);
}

int	ft_sr(t_val *val)
{
	if (val->scr_hght < 0)
		return (-1);
	val->ishere_r++;
	if (ft_zero_resolution(val) == -1)
		return (-1);
	g_proj.scr_wth = val->scr_wdth;
	g_proj.scr_hght = val->scr_hght;
	return (0);
}

int	ft_check_r(t_val *val, char *line)
{
	int	i;

	i = 0;
	i++;
	ft_skip_spaces(line, &i);
	if (line[i] >= '0' && line[i] <= '9')
		val->scr_wdth = atoi(&line[i]);
	else
		return (-1);
	if (val->scr_wdth < 0)
		return (-1);
	i += ft_nbrlen(val->scr_wdth, 10);
	ft_skip_spaces(line, &i);
	if (line[i] >= '0' && line[i] <= '9')
		val->scr_hght = atoi(&line[i]);
	else
		return (-1);
	i += ft_nbrlen(val->scr_hght, 10);
	if (line[i] != '\0')
		return (-1);
	if (ft_sr(val) == -1)
		return (-1);
	return (0);
}
