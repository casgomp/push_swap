/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:33:34 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 13:43:15 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_big_stack_bigger(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	while (t_Binfo->size < 2)
		ft_push_update(headA, headB, t_Ainfo, t_Binfo);
	while (t_Ainfo->size > 3)
	{
		ft_cost_info(*headA, *headB, t_Ainfo, t_Binfo);
		if (t_Ainfo->cost_win > 0)
			ft_big_rotator(headA, headB, t_Ainfo, t_Binfo);
		ft_push_update(headA, headB, t_Ainfo, t_Binfo);
	}
	if (*(int *)(*headB)->content != t_Binfo->max_val)
	{
		ft_rotate_find(headB, *t_Binfo);
		ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
	}
	ft_Asize_is_3(headA, headB, t_Ainfo, t_Binfo);
}

void	ft_big_rotator_op1(int val, t_list **head, void (*f)(t_list**))
{
	int	i;

	i = 0;
	while (i < val)
	{
		f(head);
		i ++;
	}
}

void	ft_big_rotator_op2(int val, t_list **headA, t_list **headB, void (*f)(t_list**, t_list**))
{
	int	i;

	i = 0;
	while (i < val)
	{
		f(headA, headB);
		i ++;
	}
}

void	ft_push_update(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	pb(headA, headB);
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
}

void	ft_rotate_find(t_list **headB, t_stack t_Binfo)
{
	while(*headB && (*(int*)(*headB)->content != t_Binfo.max_val))
	{
		if (t_Binfo.max_index <= t_Binfo.median)
			rb(headB);
		else
			rrb(headB);
	}
}
