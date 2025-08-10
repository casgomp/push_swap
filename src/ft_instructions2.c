/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:55:59 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/07 11:05:32 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ss(t_list **listA, t_list **listB)
{
	sa(listA);
	sa(listB);
	ft_printf("ss\n");
}

void	rr(t_list **listA, t_list **listB)
{
	ra(listA);
	ra(listB);
	ft_printf("rr\n");
}

void	rrr(t_list **listA, t_list **listB)
{
	rra(listA);
	rra(listB);
	ft_printf("rrr\n");
}

void	pa(t_list **list_from, t_list **list_to)
{
	t_list	*first;

	first = *list_from;
	*list_from = first->next;
	first->next = *list_to;
	*list_to = first;
	ft_printf("pa\n");
}
