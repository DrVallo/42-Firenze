/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:45:04 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 11:20:37 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = NULL;
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

/*#include <stdio.h>
int main()
{
	char *cnt= "Test";
	t_list *a = ft_lstnew((void *)cnt);
	t_list *lst = NULL;
	ft_lstadd_back(&lst, a);
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}*/
