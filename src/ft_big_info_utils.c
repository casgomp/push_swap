/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:54:29 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/17 14:29:40 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_A_min_in_B(t_list *currentA, t_list *headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	t_list	*currentB;

	currentB = headB;
	//ft_printf("ft_A_min_in_B: currentA index=%i, content=%i\n", currentA->index, *(int *)currentA->content);
	while (currentB && (*(int *)currentB->content != t_Binfo->max_val))
		currentB = currentB->next;
	//ft_printf("ft_A_min_in_B: Bmax_val=%i\n", *(int *)currentB->content);
	ft_cost_flag(currentA, currentB);
	ft_matchB(currentA, currentB, t_Ainfo);
	//ft_printf("ft_A_min_in_B: currentAcontent=%i, t_Ainfo->flag=%i, Bup=%i, Bdown=%i\n", *(int *)currentA->content, t_Ainfo->flag, currentB->up, currentB->down);
}

void	ft_A_other_in_B(t_list *currentA, t_list *headB, t_stack *t_Ainfo, t_stack *t_Binfo)
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
	if (target_val > t_Binfo->max_val)
	{
		while (currentB)
		{
			if (*(int *)currentB->content == t_Binfo->max_val)
			{
				targetB = currentB;
				break;
			}
			currentB = currentB->next;
		}
	}
	else
	{
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
	}
	ft_cost_flag(currentA, targetB);
	ft_matchB(currentA, targetB, t_Ainfo);
	//ft_printf("ft_A_other_in_B: currentA up=%i, content=%i: chosenB up=%i, content=%i: tot_u=%i\n", currentA->up, *(int *)currentA->content, targetB->up, *(int *)targetB->content, currentA->tot_u);
	//ft_printf("ft_A_other_in_B: currentA down=%i, content=%i: chosenB down=%i, content=%i: tot_d=%i\n", currentA->down, *(int *)currentA->content, targetB->down, *(int *)targetB->content, currentA->tot_d);
	//ft_printf("ft_A_other_in_B: currentA updown=%i, chosenB updown=%i: tot_ud=%i\n", currentA->updown, targetB->updown, currentA->tot_ud);	
}

/*
void	ft_A_other_in_B(t_list *currentA, t_list *headB, t_stack *t_Ainfo)
{
	t_list	*currentB;
	t_list	*targetB;
	int		dif;

	currentB = headB;
	targetB = NULL;
	dif = INT_MAX;

	while(currentB)
	{
		if(*(int *)currentB->content < *(int *)currentA->content)
		{
			if (*(int *)currentA->content - *(int *)currentB->content < dif)
			{		
				dif = *(int *)currentA->content - *(int *)currentB->content;
				targetB = currentB;
			}
		}
		currentB = currentB->next;
	}
	ft_cost_flag(currentA, targetB);
	ft_matchB(currentA, targetB, t_Ainfo);
}*/

/*void	ft_A_other_in_B(t_list *currentA, t_list *currentB, t_stack *t_Ainfo)
{
	int	costB;

	costB = INT_MAX;
	while (currentB)
	{
		ft_cost_flag(currentA, currentB);	
		if (currentA->cost < costB)
		{
			costB = currentA->cost;
			ft_matchB(currentA, currentB, t_Ainfo);
		}
		currentB = currentB->next;
	}
}*/

void	ft_matchB(t_list *currentA, t_list *currentB, t_stack *t_Ainfo)
{
	//
	(void)t_Ainfo;
	//
	currentA->matchB = currentB->index;
	//t_Ainfo->Aup = currentA->up;
	//t_Ainfo->Adown = currentA->down;
	//t_Ainfo->Bup = currentB->up;
	//t_Ainfo->Bdown = currentB->down;
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

	// Add debug output
	//ft_printf("ft_choice DEBUG: struct values: tot_u=%d, tot_d=%d, tot_ud=%d\n", 
		//currentA->tot_u, currentA->tot_d, currentA->tot_ud);
	//ft_printf("ft_choice DEBUG: local values: tot_u=%d, tot_d=%d, tot_ud=%d\n", 
		//tot_u, tot_d, tot_ud);
	
	// Test each condition explicitly
	//ft_printf("ft_choice DEBUG: tot_u <= tot_d? %d <= %d = %s\n", 
		//tot_u, tot_d, (tot_u <= tot_d) ? "TRUE" : "FALSE");
	//ft_printf("ft_choice DEBUG: tot_u <= tot_ud? %d <= %d = %s\n", 
		//tot_u, tot_ud, (tot_u <= tot_ud) ? "TRUE" : "FALSE");
	//ft_printf("ft_choice DEBUG: first condition result: %s\n",
		//(tot_u <= tot_d && tot_u <= tot_ud) ? "TRUE" : "FALSE");
	if (tot_u <= tot_d && tot_u <= tot_ud)
	{
		currentA->cost = currentA->tot_u;
		currentA->flag = 1;
		//ft_printf("ft_choice: Chose flag=1\n");
	}
	else if (tot_d <= tot_u && tot_d <= tot_ud)
	{
		currentA->cost = currentA->tot_d;
		currentA->flag = 2;
		//ft_printf("ft_choice: Chose flag=2\n");
	}
	else
	{
		currentA->cost = currentA->tot_ud;
		currentA->flag = 3;
		//ft_printf("ft_choice: Chose flag=3\n");
	}
	//ft_printf("ft_choice: tot_u=%i, tot_d=%i, tot_ud=%i, flag=%i\n", tot_u, tot_d, tot_ud, currentA->flag);
}
