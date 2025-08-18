/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:50:16 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/17 17:04:07 by pecastro         ###   ########.fr       */
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
	int	position;

	stack_info->size = 0;
	stack_info->median = 0.0;
	stack_info->min_val = INT_MAX;
	stack_info->max_val = INT_MIN;
	position = 1;
	while (head)
	{
		if (*(int *)head->content < stack_info->min_val)
		{
			stack_info->min_val = *(int *)head->content;
			stack_info->min_index = position;;
			stack_info->min_content = *(int *)head->content;
		}
		if (*(int *)head->content > stack_info->max_val)
		{
			stack_info->max_val = *(int *)head->content;
			//ft_printf("ft_stack_info: max_val(%i) = head->content(%i)\n", stack_info->max_val, *(int *)head->content);
			stack_info->max_index = position;
			//ft_printf("ft_stack_info: max_index(%i) = position(%i)\n", stack_info->max_index, position);
			stack_info->max_content = *(int *)head->content;
		}
		head = head->next;
		stack_info->size ++;
		position ++;
	}
	if (stack_info->size > 1)
		stack_info->median = stack_info->size / 2.0 + 0.5;
	//printf("ft_stack_info: median = size(%i) / 2.0 + 0.5 =%.1f\n", stack_info->size, stack_info->median);
	//ft_printf("ft_stack_info: max_val=%i, max_index=%i\n", stack_info->max_val, stack_info->max_index);
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
		//ft_printf("ft_node_info: for %i, up(%i) = %i - 1, down(%i) = %i - %i + 1\n", *(int *)head->content, head->up, head->index, head->down, stack_info->size, head->index);
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
			ft_A_min_in_B(currentA, headB, t_Ainfo, t_Binfo);	
		else
			ft_A_other_in_B(currentA, headB, t_Ainfo, t_Binfo);
		//ft_printf("ft_cost_info: currentA content=%i, cost=%i, flag=%i\n", *(int *)currentA->content, currentA->cost, currentA->flag);
		if (currentA->cost < t_Ainfo->cost_win)
		{
			ft_info_winner(currentA, t_Ainfo);
			//ft_printf("ft_cost_info: Awinner index=%i, content=%i, cost=%i; t_Ainfo->cost_win=%i\n", currentA->index, *(int *)currentA->content, currentA->cost, t_Ainfo->cost_win);
		}
		currentA = currentA->next;
	}
}
