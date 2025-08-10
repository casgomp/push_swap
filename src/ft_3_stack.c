/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:53:02 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/07 11:16:05 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_3stack(t_list **head, int size) //this function should be void?
{
	int	arr_cont[size];

	//ft_printf("succesfully made it to ft_3_stack\n");//get rid of this debugging statement
	ft_3_update_cont(*head, arr_cont);
	if (size == 3)
	{
		if (ft_3_first_smallest(arr_cont[0], arr_cont[1], arr_cont[2]))
		{
			if (ft_3_islarger(arr_cont[2], arr_cont[1])) //ops_center has ifsorted so this if not necessary.
				return ;
			else
			{
				sa(head); 
				ft_3_update_cont(*head, arr_cont);
				ra(head);
				ft_3_update_cont(*head, arr_cont);
				return ;
			}
		}
		if (ft_3_first_largest(arr_cont[0], arr_cont[1], arr_cont[2]))
		{
			ra(head);
			ft_3_update_cont(*head, arr_cont);
		}
		if (ft_3_third_smallest(arr_cont[0], arr_cont[1], arr_cont[2]))
		{	
			rra(head);
			ft_3_update_cont(*head, arr_cont);
		}
	}
	if (ft_3_islarger(arr_cont[0], arr_cont[1]))
	{
		sa(head);
	}
	ft_3_update_cont(*head, arr_cont);
/*	//starts debugging loops .............................................get rid
	int i = 0;
	while (i < size)
	{
		//ft_printf("updated arr_cont[%i] = %i\n", i, arr_cont[i]);
		i ++;
	}
	t_list *current = *head;
	while (current)
	{
		//ft_printf("updated list: current->content = %i\n", *(int *)current->content);
		current = current->next;
	}
	//ends debugging loops ...............................................get rid/*/
}

void	ft_3_update_cont(t_list *head, int *arr_cont)
{
	t_list	*current;
	int		i;

	//ft_printf("succesfully made it to ft_3_update_cont\n");
	current = head;
	i = 0;
	while (current)
	{
		arr_cont[i] = *(int *)current->content;
		//ft_printf("arr_cont[%i] = %i\n", i, arr_cont[i]);
		current = current->next;
		i ++;
	}
}
