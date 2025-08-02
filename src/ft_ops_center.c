/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:56:46 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/02 12:46:37 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_ops_center(t_list *head, int size)
{
	if (ft_is_sorted(head)) //free list before and return end of function?
		return (0);
	if (size <= 1)
		return (0);
	else if (size <= 3)
		return (ft_3stack(head, size));
	else if (size <= 500)
		return (500);//return ft_500stack?????
	return (1);
}

int	ft_is_sorted(t_list *head)
{
	t_list	*current;
	int		flag;
	int		max_value;

	current = head;
	max_value = 0;
	flag = 0;
	while (current)
	{
		if (*(int *)current->content > max_value)
			max_value = *(int *)current->content;
		if (*(int *)current->content < max_value)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (flag == 1)
	{
	//ft_printf("list is unsorted\n"); //get rid of this debugging statement before submitting
		return (0);
	}
	//ft_printf("list is sorted\n"); //get rid of this debugging statement before submitting
	return (1);
}
