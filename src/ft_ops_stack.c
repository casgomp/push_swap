/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:56:46 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/07 11:19:09 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_ops_stack(int *arr_int, int size)
{
	t_list	*head;

	head = ft_list_create(arr_int, size);
	if (ft_is_sorted(head) || size <= 1)
		return (0);
	if (size <= 3)
		ft_3stack(&head, size);
	else if (size <= 500)
		ft_big_stack(&head, size);
	ft_clean_list(&head);
	return (1);
}

int	ft_is_sorted(t_list *head)
{
	t_list	*current;
	int		flag;
	int		max_value;

	current = head;
	max_value = INT_MIN;
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
		return (0);
	//ft_printf("list is sorted\n"); //get rid of this debugging statement before submitting
	return (1);
}
