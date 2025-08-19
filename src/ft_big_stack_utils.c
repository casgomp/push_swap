/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:33:34 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 12:30:23 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_big_stack_bigger(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	while (t_binfo->size < 2)
		ft_push_update(heada, headb, t_ainfo, t_binfo);
	while (t_ainfo->size > 3)
	{
		ft_cost_info(*heada, *headb, t_ainfo, t_binfo);
		if (t_ainfo->cost_win > 0)
			ft_big_rotator(heada, headb, t_ainfo, t_binfo);
		ft_push_update(heada, headb, t_ainfo, t_binfo);
	}
	if (*(int *)(*headb)->content != t_binfo->max_val)
	{
		ft_rotate_find(headb, *t_binfo);
		ft_update_info(*heada, *headb, t_ainfo, t_binfo);
	}
	ft_asize_is_3(heada, headb, t_ainfo, t_binfo);
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

void	ft_big_rotator_op2(int val, t_list **heada, t_list **headb, 
			void (*f)(t_list**, t_list**))
{
	int	i;

	i = 0;
	while (i < val)
	{
		f(heada, headb);
		i ++;
	}
}

void	ft_push_update(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	pb(heada, headb);
	ft_update_info(*heada, *headb, t_ainfo, t_binfo);
}

void	ft_rotate_find(t_list **headb, t_stack t_binfo)
{
	while (*headb && (*(int *)(*headb)->content != t_binfo.max_val))
	{
		if (t_binfo.max_index <= t_binfo.median)
			rb(headb);
		else
			rrb(headb);
	}
}
