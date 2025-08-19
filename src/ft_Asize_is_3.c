/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Asize_is_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:57:47 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 10:46:48 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h" 

void	ft_Asize_is_3(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	if(!ft_is_sorted(*headA))
		ft_3stack(headA, t_Ainfo->size);
	if (t_Binfo->size == 2)
	{
		if (ft_is_sorted(*headB))
			sb(headB);
	}
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
	while (*headB)
	{
		ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
		ft_Asize_is_3_Awin(*headA, *headB, t_Ainfo);
		if (t_Ainfo->min_dif < INT_MAX)
			ft_Asize_is_3_rotator(headA, headB, t_Ainfo, t_Binfo);
		else
			ft_Asize_is_3_Blarger(headA, t_Ainfo);
		pa(headB, headA);
	}
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
	if (*(int *)(*headA)->content != t_Ainfo->min_val)
	{	
		while (*(int *)(*headA)->content != t_Ainfo->min_val)
			rra(headA);
	}
}

void	ft_Asize_is_3_Awin(t_list *headA, t_list *headB, t_stack *t_Ainfo)
{
	t_list *currentA;
	int	result;

	t_Ainfo->min_dif = INT_MAX;
	currentA = headA;
	while(currentA)
	{
		result = *(int *)currentA->content - *(int *)(headB)->content;
		if (result > 0 && result < t_Ainfo->min_dif)
		{
			t_Ainfo->min_dif = result;
			t_Ainfo->Awin = currentA->index;
		}
		currentA = currentA->next;
	}
}

void	ft_Asize_is_3_rotator(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	if (t_Ainfo->Awin <= t_Ainfo->median)
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

void	ft_Asize_is_3_Blarger(t_list **headA, t_stack *t_Ainfo)
{
	if (t_Ainfo->min_index <= t_Ainfo->median)
	{
		while (*(int *)(*headA)->content != t_Ainfo->min_content)
			ra(headA);
	}
	else
	{
		while (*(int *)(*headA)->content != t_Ainfo->min_content)
			rra(headA);
	}
}
