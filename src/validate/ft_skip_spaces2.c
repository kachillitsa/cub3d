/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:14:05 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 12:42:09 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_skip_spaces2(char *line, int *i)
{
	if (line[*i] == ',')
		*i = *i + 1;
	else
		return (-1);
	while (line[*i] == ' ')
		*i = *i + 1;
	return (0);
}
