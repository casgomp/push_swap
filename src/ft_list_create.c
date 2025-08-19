/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:41:02 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 11:59:36 by pecastro         ###   ########.fr       */
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
	return (head); 
}
