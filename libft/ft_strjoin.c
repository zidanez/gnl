/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:12:26 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/12 17:12:26 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	if (s1 && s2)
	{
		i = -1;
		if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		else
		{
			while (++i < (int)ft_strlen(s1))
				res[i] = s1[i];
			while (*s2)
			{
				res[i] = *s2;
				i++;
				s2++;
			}
			res[i] = '\0';
			return (res);
		}
	}
	return (NULL);
}
