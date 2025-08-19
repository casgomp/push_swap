/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:50:16 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 12:23:50 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_update_info(t_list *heada, t_list *headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	ft_stack_info(heada, t_ainfo);
	ft_stack_info(headb, t_binfo);
	ft_node_info(heada, t_ainfo);
	ft_node_info(headb, t_binfo);
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

void	ft_cost_info(t_list *heada, t_list *headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	t_list	*currenta;
	t_list	*currentb;

	t_ainfo->cost_win = INT_MAX;
	currenta = heada;
	while (currenta)
	{
		currentb = headb;
		if (*(int *)currenta->content < t_binfo->min_val)
			ft_a_min_in_b(currenta, headb, t_binfo);
		else
			ft_a_other_in_b(currenta, headb);
		if (currenta->cost < t_ainfo->cost_win)
			ft_info_winner(currenta, t_ainfo);
		currenta = currenta->next;
	}
}
