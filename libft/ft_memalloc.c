/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:20:41 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/09 19:20:41 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	else
	{
		while (size != 0)
		{
			res[size] = (unsigned char)0;
			size--;
		}
		res[size] = (unsigned char)0;
		return ((void *)res);
	}
}
