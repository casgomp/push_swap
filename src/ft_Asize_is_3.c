/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Asize_is_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:57:47 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/14 11:03:02 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h" 

void	ft_Asize_is_3(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	int	arr_cont[t_Ainfo->size];
	int	arr_result[t_Ainfo->size];
	int	i;
	
	if(!ft_is_sorted(*headA))
		ft_3stack(headA, t_Ainfo->size);
	if (t_Binfo->size == 2)
	{
		if (ft_is_sorted(*headB))
			sa(headB);
	}
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
	while (*headB) //loop in another function?
	{
		ft_3_update_cont(*headA, arr_cont);
		ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
		t_Ainfo->min_dif = INT_MAX;
		i = 0;
		while (i < t_Ainfo->size)
		{
			arr_result[i] = arr_cont[i] - *(int *)(*headB)->content;
			if (arr_result[i] > 0 && arr_result[i] < t_Ainfo->min_dif)
				t_Ainfo->min_dif = arr_result[i];
			i ++;
		}
		if (t_Ainfo->min_dif < INT_MAX)
			ft_Asize_is_3_rotator(headA, headB, t_Ainfo, t_Binfo);
		pa(headB, headA);
	}
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
	//if min_val not at index 1, then rotate until it is. (maybe could use
	//a function used to calculate cost fo knwing if its better to rotate
	//ra or rra. In the meantime I'll assume best way is always rra:
	if (*(int *)(*headA)->content != t_Ainfo->min_val)
	{	
		while (*(int *)(*headA)->content != t_Ainfo->min_val)
			rra(headA);
	}
	//debugging loop:............................................................................debugging loop
	t_list *current = *headA;
	i = 0;
	while (current)
	{
		ft_printf("sorted list stackA, index[%i] = %i\n", i, *(int *)current->content);
		i ++;
		current = current->next;
	}
	//debugging loop:............................................................................debugging loop /*/
}

void	ft_Asize_is_3_rotator(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	if (t_Ainfo->min_dif <= t_Ainfo->median)
		{
			while (*headB && ((*(int *)(*headA)->content - *(int *)(*headB)->content) != t_Ainfo->min_dif))
			{
				ra(headA);
				ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
			}
		}
	else
		{
			while ((*headB && (*(int *)(*headA)->content - *(int *)(*headB)->content) != t_Ainfo->min_dif))
			{
				rra(headA);
				ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
			}
		}
}
