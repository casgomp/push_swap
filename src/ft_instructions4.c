/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:16:55 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 13:08:15 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	swap(t_list **list)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;

	first = *list;
	last = ft_lstlast(*list);
	*list = first->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*last_new;

	first = *list;
	last = ft_lstlast(*list);
	last_new = *list;
	while (last_new && (last_new->next)->next)
		last_new = last_new->next;
	last->next = first;
	last_new->next = NULL;
	*list = last;
}
