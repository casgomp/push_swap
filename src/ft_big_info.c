/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:50:16 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 09:57:14 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_update_info(t_list *headA, t_list *headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	ft_stack_info(headA, t_Ainfo);
	ft_stack_info(headB, t_Binfo);
	ft_node_info(headA, t_Ainfo);
	ft_node_info(headB, t_Binfo);
}

void	ft_stack_info(t_list *head, t_stack *stack_info)
{
	stack_info->size = 0;
	stack_info->median = 0.0;
	stack_info->min_val = INT_MAX;
	stack_info->max_val = INT_MIN;
	ft_stack_info_loop(head, stack_info);
	if (stack_info->size > 1)
		stack_info->median = stack_info->size / 2.0 + 0.5;
}

void	ft_stack_info_loop(t_list *head, t_stack *stack_info)
{
	int	position;
	
	position = 1;
	while (head)
	{
		if (*(int *)head->content < stack_info->min_val)
		{
			stack_info->min_val = *(int *)head->content;
			stack_info->min_index = position;
			stack_info->min_content = *(int *)head->content;
		}
		if (*(int *)head->content > stack_info->max_val)
		{
			stack_info->max_val = *(int *)head->content;
			stack_info->max_index = position;
			stack_info->max_content = *(int *)head->content;
		}
		head = head->next;
		stack_info->size ++;
		position ++;
	}
}

void	ft_node_info(t_list *head, t_stack *stack_info)
{
	int	i;

	i = 0;
	while (head)
	{
		i ++;
		head->index = i;
		head->up = head->index - 1;
		head->down = stack_info->size - head->index + 1;
		if (head->index <= stack_info->median)
		{
			head->half = 1;
			head->updown = head->up;
		}
		else
		{
			head->half = 0;
			head->updown = head->down;
		}
		head = head->next;
	}
}

void	ft_cost_info(t_list *headA, t_list *headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	t_list	*currentA;
	t_list	*currentB;

	t_Ainfo->cost_win = INT_MAX;
	currentA = headA;
	while (currentA)
	{
		currentB = headB;
		if (*(int *)currentA->content < t_Binfo->min_val)
			ft_A_min_in_B(currentA, headB, t_Binfo);	
		else
			ft_A_other_in_B(currentA, headB);
		if (currentA->cost < t_Ainfo->cost_win)
			ft_info_winner(currentA, t_Ainfo);
		currentA = currentA->next;
	}
}
