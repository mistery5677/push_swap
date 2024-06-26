/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:38:06 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/09 09:38:07 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst)
	{
		while ((*lst) != NULL)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
	}
}

/*void delete_lst(void *content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list *head  = malloc(sizeof(t_list));

	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "Node 1";
	node2->content = "Node 2";
	node3->content = "Node 3";

	head->next = node3;
	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;

	printf("before free: %s\n", (char *)node2->content);
	ft_lstclear(&head, &delete_lst);
}*/