/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getposchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:52:37 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/20 13:52:37 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getposchr(const char *s1, int ch)
{
	int pos;

	if (!s1)
		return (-1);
	pos = -1;
	while (*s1 != ch && *s1)
	{
		s1++;
		pos++;
	}
	if (*s1 == '\0')
		return (-1);
	else
		return (pos);
}
