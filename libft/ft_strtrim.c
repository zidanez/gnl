/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:57:53 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/12 17:57:53 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	counter;
	size_t	l;
	size_t	beg;
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (!(*s))
		return ("");
	i = -1;
	counter = 0;
	l = ft_strlen(s);
	while ((++i != 2147483647) && ((s[i] == '\n' || s[i] == '\t'
			|| s[i] == ' ') && (s[i])))
		counter++;
	beg = i - 1;
	while (--l && (s[l] == '\n' || s[l] == '\t' || s[l] == ' ') && (s[i]))
		counter++;
	i = -1;
	if (!(res = ft_strnew(ft_strlen(s) - counter)))
		return (NULL);
	while (++beg <= l && ++i != 2147483647)
		res[i] = s[beg];
	return (res);
}
