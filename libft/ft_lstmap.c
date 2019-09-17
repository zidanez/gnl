/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:28:37 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/14 19:28:37 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_null_return(t_list **res)
{
	t_list	*ptr;
	t_list	*nxt_it;
	t_list	*nxt_nxt;

	ptr = *res;
	nxt_it = ptr->next;
	while (nxt_it->next != NULL)
	{
		nxt_nxt = nxt_it->next;
		free(nxt_it);
		nxt_it = nxt_nxt;
	}
	free(nxt_it);
	free(ptr);
	nxt_nxt = NULL;
	ptr = NULL;
	nxt_it = NULL;
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*help;

	if (lst)
	{
		if (!(res = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		help = res;
		lst = lst->next;
		while (lst->next != NULL)
		{
			if (!(res->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
				return (free_null_return(&help));
			lst = lst->next;
			res = res->next;
		}
		if (!(res->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (free_null_return(&res));
		return (help);
	}
	return (NULL);
}
