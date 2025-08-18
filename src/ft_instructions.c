/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:43:35 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 10:13:00 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sa(t_list **list)
{
	swap(list);
	ft_printf("sa\n");
/*	//debugging loop:............................................................................debugging loop
	t_list *current = *list;
	int i = 0;
	while (current)
	{
		ft_printf("after, index[%i] = %i\n", i, *(int *)current->content);
		i ++;
		current = current->next;
	}
	//debugging loop:............................................................................debugging loop/*/
}

void	sb(t_list **list)
{
	swap(list);
	ft_printf("sb\n");
}

void	ra(t_list **list)
{
	rotate(list);
	ft_printf("ra\n");
/*	//debugging loop:............................................................................debugging loop
	t_list *current = *list;
	int i = 0;
	while (current)
	{
		ft_printf("after, index[%i] = %i\n", i, *(int *)current->content);
		i ++;
		current = current->next;
	}
	//debugging loop:............................................................................debugging loop/*/
}

void	rb(t_list **list)
{
	rotate(list);
	ft_printf("rb\n");
}

void	rra(t_list **list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
/*	//debugging loop:............................................................................debugging loop
	t_list *current = *list;
	int i = 0;
	while (current)
	{
		ft_printf("after, index[%i] = %i\n", i, *(int *)current->content);
		i ++;
		current = current->next;
	}
	//debugging loop:............................................................................debugging loop/*/

}

void	rrb(t_list **list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}
