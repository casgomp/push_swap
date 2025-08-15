/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:54:29 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/15 19:12:29 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_A_min_in_B(t_list *currentA, t_list *currentB, t_stack *t_Ainfo, t_stack *t_Binfo)
{	
	while (currentB && (*(int *)currentB->content != t_Binfo->max_val))
		currentB = currentB->next;
	ft_cost_flag(currentA, currentB);
	ft_matchB(currentA, currentB, t_Ainfo);
}

void	ft_A_other_in_B(t_list *currentA, t_list *currentB, t_stack *t_Ainfo)
{
	int	costB;

	costB = INT_MAX;
	while (currentB)
	{
		ft_cost_flag(currentA, currentB);	
		if (currentA->cost < costB)
			ft_matchB(currentA, currentB, t_Ainfo);
		currentB = currentB->next;
	}
}

void	ft_matchB(t_list *currentA, t_list *currentB, t_stack *t_Ainfo)
{
	currentA->matchB = currentB->index;
	t_Ainfo->Aup = currentA->up;
	t_Ainfo->Adown = currentA->down;
	t_Ainfo->Bup = currentB->up;
	t_Ainfo->Bdown = currentB->down;
}

void	ft_info_winner(t_list *currentA, t_stack *t_Ainfo)
{	
	t_Ainfo->cost_win = currentA->cost;
	t_Ainfo->Awin = currentA->index;
	t_Ainfo->Bwin = currentA->matchB;
	t_Ainfo->flag = currentA->flag;
}

void	ft_cost_flag(t_list *currentA, t_list *currentB)
{
	currentA->tot_u = ft_eq_larger(currentA->up, currentB->up);
	currentA->tot_d = ft_eq_larger(currentA->down, currentB->down);
	currentA->tot_ud = currentA->updown + currentB->updown;
	ft_choice(currentA);
}

int	ft_eq_larger(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

void	ft_choice(t_list *currentA)
{
	int	tot_u;
	int	tot_d;
	int	tot_ud;

	tot_u = currentA->tot_u;
	tot_d = currentA->tot_d;
	tot_ud = currentA->tot_ud;
	if (tot_u <= tot_d && tot_u <= tot_ud)
	{
		currentA->cost = currentA->tot_u;
		currentA->flag = 1;
	}
	else if (tot_d <= tot_u && tot_d <= tot_ud)
	{
		currentA->cost = currentA->tot_d;
		currentA->flag = 2;
	}
	else
	{
		currentA->cost = currentA->tot_ud;
		currentA->flag = 3;
	}
}
