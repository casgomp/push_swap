/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:54:29 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 12:25:10 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_a_min_in_b(t_list *currenta, t_list *headb, t_stack *t_binfo)
{
	t_list	*currentb;

	currentb = headb;
	while (currentb && (*(int *)currentb->content != t_binfo->max_val))
		currentb = currentb->next;
	ft_cost_flag(currenta, currentb);
	ft_matchb(currenta, currentb);
}

void	ft_a_other_in_b(t_list *currenta, t_list *headb)
{
	t_list	*currentb;
	t_list	*targetb;
	int		target_val;
	int		dif;
	int		b_val;

	currentb = headb;
	targetb = NULL;
	target_val = *(int *)currenta->content;
	dif = INT_MAX;
	while (currentb)
	{
		b_val = *(int *)currentb->content;
		if (b_val < target_val)
		{
			if (target_val - b_val < dif)
			{
				dif = target_val - b_val;
				targetb = currentb;
			}
		}
		currentb = currentb->next;
	}
	ft_cost_flag(currenta, targetb);
	ft_matchb(currenta, targetb);
}

void	ft_matchb(t_list *currenta, t_list *currentb)
{
	currenta->matchb = currentb->index;
	currenta->matchb = currentb->index;
	currenta->bup_match = currentb->up;
	currenta->bdown_match = currentb->down;
}

void	ft_info_winner(t_list *currenta, t_stack *t_ainfo)
{
	t_ainfo->cost_win = currenta->cost;
	t_ainfo->awin = currenta->index;
	t_ainfo->bwin = currenta->matchb;
	t_ainfo->flag = currenta->flag;
	t_ainfo->aup = currenta->up;
	t_ainfo->adown = currenta->down;
	t_ainfo->bup = currenta->bup_match;
	t_ainfo->bdown = currenta->bdown_match;
}

void	ft_cost_flag(t_list *currenta, t_list *currentb)
{
	currenta->tot_u = ft_eq_larger(currenta->up, currentb->up);
	currenta->tot_d = ft_eq_larger(currenta->down, currentb->down);
	currenta->tot_ud = currenta->updown + currentb->updown;
	ft_choice(currenta);
}
