/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparviai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:47:04 by eparviai          #+#    #+#             */
/*   Updated: 2019/10/31 13:47:05 by eparviai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*start;
	t_list		*mapped;

	if (!lst || !f)
		return (NULL);
	if (!(mapped = f(lst)))
		return (NULL);
	start = mapped;
	while (lst->next)
	{
		lst = lst->next;
		if (!(mapped->next = f(lst)))
			return (NULL);
		mapped = mapped->next;
	}
	return (start);
}
