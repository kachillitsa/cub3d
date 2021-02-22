/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 23:36:59 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/25 23:37:02 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *string1, const char *string2)
{
	size_t index;

	index = 0;
	while (string1[index] == string2[index])
	{
		if (string1[index] == '\0')
		{
			return (0);
		}
		index++;
	}
	return ((unsigned char)string1[index] - (unsigned char)string2[index]);
}
