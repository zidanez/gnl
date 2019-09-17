/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:03:55 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/12 17:03:55 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	char			*r;
	unsigned int	i;

	if (s && len != 0)
	{
		i = start;
		if (!(res = ft_strnew(len)))
			return (NULL);
		else
		{
			r = res;
			while (len--)
			{
				*res = s[i];
				res++;
				i++;
			}
			return (r);
		}
	}
	return (NULL);
}
