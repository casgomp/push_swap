/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:53:02 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 12:27:45 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_3stack(t_list **head, int size)
{
	int	arr_cont[size];

	ft_3_update_cont(*head, arr_cont);
	if (size == 3)
	{
		if (ft_3_first_smallest(arr_cont[0], arr_cont[1], arr_cont[2]))
		{
			if (ft_3_islarger(arr_cont[2], arr_cont[1]))
				return ;
			else
			{
				ft_3_ops_and_update(head, arr_cont, sa); 
				ft_3_ops_and_update(head, arr_cont, ra);
				return ;
			}
		}
		if (ft_3_first_largest(arr_cont[0], arr_cont[1], arr_cont[2]))
			ft_3_ops_and_update(head, arr_cont, ra);
		if (ft_3_third_smallest(arr_cont[0], arr_cont[1], arr_cont[2]))
			ft_3_ops_and_update(head, arr_cont, rra);
	}
	if (ft_3_islarger(arr_cont[0], arr_cont[1]))
		ft_3_ops_and_update(head, arr_cont, sa);
	ft_3_update_cont(*head, arr_cont);
}

void	ft_3_ops_and_update(t_list **head, int *arr_cont, void (*f)(t_list **))
{
	f(head);
	ft_3_update_cont(*head, arr_cont);
}

void	ft_3_update_cont(t_list *head, int *arr_cont)
{
	t_list	*current;
	int		i;

	current = head;
	i = 0;
	while (current)
	{
		arr_cont[i] = *(int *)current->content;
		current = current->next;
		i ++;
	}
}
