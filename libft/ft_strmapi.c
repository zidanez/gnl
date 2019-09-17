/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:37:14 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/12 15:37:14 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*r;
	unsigned int	index;

	if (s && f)
	{
		if (!(res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		else
		{
			r = res;
			index = 0;
			while (*s)
			{
				*res = f(index, *s);
				s++;
				index++;
				res++;
			}
			*res = '\0';
		}
		return (r);
	}
	return (NULL);
}
