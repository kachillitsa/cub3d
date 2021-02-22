/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:07:44 by bjebedia          #+#    #+#             */
/*   Updated: 2020/10/29 13:07:58 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_4(char **line1, char **line2, char **line3, char **line4)
{
	if (*line1)
		free(*line1);
	if (*line2)
		free(*line2);
	if (*line3)
		free(*line3);
	if (*line4)
		free(*line4);
}
