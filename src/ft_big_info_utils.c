/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:54:29 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 10:49:08 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_A_min_in_B(t_list *currentA, t_list *headB, t_stack *t_Binfo)
{
	t_list	*currentB;

	currentB = headB;
	while (currentB && (*(int *)currentB->content != t_Binfo->max_val))
		currentB = currentB->next;
	ft_cost_flag(currentA, currentB);
	ft_matchB(currentA, currentB);
}

void	ft_A_other_in_B(t_list *currentA, t_list *headB)
{
	t_list	*currentB;
	t_list	*targetB;
	int		target_val;
	int		dif;
	int		b_val;

	currentB = headB;
	targetB = NULL;
	target_val = *(int *)currentA->content;
	dif = INT_MAX;
	while (currentB)
	{
		b_val = *(int *)currentB->content;
		if (b_val < target_val)
		{
			if (target_val - b_val < dif)
			{
				dif = target_val - b_val;
				targetB = currentB;
			}
		}
		currentB = currentB->next;
	}
	ft_cost_flag(currentA, targetB);
	ft_matchB(currentA, targetB);
}

void	ft_matchB(t_list *currentA, t_list *currentB)
{
	currentA->matchB = currentB->index;
	currentA->matchB = currentB->index;
	currentA->Bup_match = currentB->up;
	currentA->Bdown_match = currentB->down;
}

void	ft_info_winner(t_list *currentA, t_stack *t_Ainfo)
{	
	t_Ainfo->cost_win = currentA->cost;
	t_Ainfo->Awin = currentA->index;
	t_Ainfo->Bwin = currentA->matchB;
	t_Ainfo->flag = currentA->flag;
	//
	t_Ainfo->Aup = currentA->up;
	t_Ainfo->Adown = currentA->down;
	t_Ainfo->Bup = currentA->Bup_match;
	t_Ainfo->Bdown = currentA->Bdown_match;
}

void	ft_cost_flag(t_list *currentA, t_list *currentB)
{
	currentA->tot_u = ft_eq_larger(currentA->up, currentB->up);
	currentA->tot_d = ft_eq_larger(currentA->down, currentB->down);
	currentA->tot_ud = currentA->updown + currentB->updown;
	ft_choice(currentA);
}
