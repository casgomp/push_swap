/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:43:35 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/06 12:55:43 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sa(t_list **list)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
	ft_printf("sa\n");
}

void	ra(t_list **list)
{
	t_list	*first;
	t_list	*last;

	first = *list;
	last = ft_lstlast(*list);
	*list = first->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rra(t_list **list)
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
	ft_printf("rra\n");
}
