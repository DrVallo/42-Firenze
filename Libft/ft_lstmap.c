/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:45:45 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 11:25:10 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!new)
			ft_lstclear(&new, del);
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	temp = NULL;
	return (new);
}
