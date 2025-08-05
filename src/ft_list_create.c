/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:41:02 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/04 11:46:42 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_list	*ft_list_create(int *arr, int size)
{
	t_list	*node;
	t_list	*head;
	t_list	**lst;
	int		i;

	head = NULL;
	lst = &head;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew(&arr[i]);
		if (!node)
			return (NULL);
		ft_lstadd_back(lst, node);
		i ++;
	}
/*	t_list *curr = *lst;
	i = 0;
    while (curr != NULL)
	{
		printf("fourth addback address of [%i] is %p\n", i, curr);
		printf("fourth addback content of [%i] is %i\n", i, *(int *)curr->content);
		printf("fourth addback next of [%i] is %p\n", i, curr->next);
		curr = curr->next;
		i ++;
	}*/	
	return (head); 
}

//wherever ownership chain ends must add ft_lstclear and create *(del) function.
//maybe have a ft_cleaning.c file where all cleaning functions are concentrated.


