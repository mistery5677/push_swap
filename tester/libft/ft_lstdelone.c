/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:58:17 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 13:58:19 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void delete_lst(char *content)
{
	free(content);
}

int	main(void)
{
	t_list *head;

	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "Node 1";
	node2->content = "Node 2";
	node3->content = "Node 3";

	node3->next = node2;
	node2->next = node1;
	node1->next = NULL;

	printf("before free: %s\n", (char *)node2->content);
	ft_lstdelone(node2, &delete_lst);
	printf("content free");
	free(node1);
	free(node3);
}*/