/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:52:49 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/13 20:52:49 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = ft_ilen(n);
	if (!(res = ft_strnew(ft_ilen(n))))
		return (NULL);
	if (n == 0)
		res[i - 1] = '0';
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strcpy(res, "-2147483648"));
		else
		{
			res[0] = '-';
			n = n * -1;
		}
	}
	while (n != 0)
	{
		res[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (res);
}
