/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:23:35 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/16 11:27:39 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_big_stack(t_list **headA)
{
	t_list	*headB;
	t_stack	t_Ainfo;
	t_stack	t_Binfo;

	headB = NULL;
	ft_update_info(*headA, headB, &t_Ainfo, &t_Binfo);
	
	//debugging loop:............................................................................debugging loop
	t_list *current = *headA;
	int i = 0;
	while (current)
	{
		ft_printf("before, list_from,index[%i] = %i\n", i, *(int *)current->content);
		i ++;
		current = current->next;
	}
	current = headB;
	i = 0;
	while (current)
	{
		ft_printf("before, list_to,index[%i] = %i\n", i, *(int *)current->content);
		i ++;
		current = current->next;
	}
	//debugging loop:............................................................................debugging loop


	printf("ft_big_stack:first_update: Amedian=%.1f, Bmedian=%.1f\n", t_Ainfo.median, t_Binfo.median);
	ft_printf("ft_big_stack: first update: Bsize=%i Asize=%i\n", t_Ainfo.size, t_Binfo.size);
	if (t_Ainfo.size <= 5)//this small loop is for only input of size <= 5.
	{
		while (t_Ainfo.size > 3)
			ft_push_update(headA, &headB, &t_Ainfo, &t_Binfo);
		ft_Asize_is_3(headA, &headB, &t_Ainfo, &t_Binfo);
	}
	else
	{
		while (t_Binfo.size < 2)
			ft_push_update(headA, &headB, &t_Ainfo, &t_Binfo);
		while (t_Ainfo.size > 3)
		{
			ft_cost_info(*headA, headB, &t_Ainfo, &t_Binfo);//calculate which A to push to B.
			ft_printf("ft_big_stack: flag=%i, cost_win=%i, Awin=%i, Bwin=%i\n", t_Ainfo.flag, t_Ainfo.cost_win, t_Ainfo.Awin, t_Ainfo.Bwin);
			printf("ft_big_stack: Asize=%i, Bsize=%i, Amedian=%.1f, Bmedian=%.1f\n", t_Ainfo.size, t_Binfo.size, t_Ainfo.median, t_Binfo.median);
			ft_big_rotator(headA, &headB, &t_Ainfo, &t_Binfo); //rotate A and B based on flag
 			ft_push_update(headA, &headB, &t_Ainfo, &t_Binfo); //push A to B and update
		}
		ft_Asize_is_3(headA, &headB, &t_Ainfo, &t_Binfo);
	}
	//ft_clean_list(&headB); //redundant? At this point all B members are in A and headB is pointing at NULL.
}

void	ft_big_rotator(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	ft_printf("ft_big_rotator: flag=%i\n", t_Ainfo->flag);
	if (t_Ainfo->flag == 1)
		ft_big_rotator_flag1(headA, headB, t_Ainfo);
	else if (t_Ainfo->flag == 2)
		ft_big_rotator_flag2(headA, headB, t_Ainfo);
	else
		ft_big_rotator_flag3(headA, headB, t_Ainfo, t_Binfo);
}

void	ft_big_rotator_flag1(t_list **headA, t_list **headB, t_stack *t_Ainfo)
{
	int	dif;
	int	i;

	if (t_Ainfo->Aup < t_Ainfo->Bup)
	{
		i = 0;
		while (i < t_Ainfo->Aup) //this loop appears x4 in flag1 and 2 functions
		//maybe create one function for rr and one for ra so i can pass the functions as ptr.
		{
			rr(headA, headB);
			i ++;
		}
		dif = t_Ainfo->Bup - t_Ainfo->Aup;
  		i = 0;
		while (i < dif)
		{
			ra(headB);
			i ++;
		}
	}
	else
	{
		i = 0;
		while (i < t_Ainfo->Bup)
		{
			rr(headA, headB);
			i ++;
		}
		dif = t_Ainfo->Aup - t_Ainfo->Bup;
   		i = 0;
		while (i < dif)
		{
			ra(headA);
			i ++;
		}
	}
}

void	ft_big_rotator_flag2(t_list **headA, t_list **headB, t_stack *t_Ainfo)
{
	int	dif;
	int	i;

	if (t_Ainfo->Adown < t_Ainfo->Bdown)
	{
		i = 0;
		while (i < t_Ainfo->Adown)
		{
			rrr(headA, headB);
			i ++;
		}
		dif = t_Ainfo->Bdown - t_Ainfo->Adown;
  		i = 0;
		while (i < dif)
		{
			rra(headB);
			i ++;
		}
	}
	else
	{
		i = 0;
		while (i < t_Ainfo->Bdown)
		{
			rrr(headA, headB);
			i ++;
		}
		dif = t_Ainfo->Adown - t_Ainfo->Bdown;
   		i = 0;
		while (i < dif)
		{
			rra(headA);
			i ++;
		}
	}
}

void	ft_big_rotator_flag3(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	int	i;

	i = 0;
	if (t_Ainfo->Awin <= t_Ainfo->median)
	{
		while (i < t_Ainfo->Aup)
		{
			ra(headA);
			i ++;
		}
	}
	else
	{
		while (i < t_Ainfo->Adown)
		{
			rra(headA);
			i ++;
		}
	}
	i = 0;
	if (t_Ainfo->Bwin <= t_Binfo->median)
	{
		while (i < t_Ainfo->Bup)
		{
			ra(headB);
			i ++;
		}
	}
	else
	{
		while (i < t_Ainfo->Bdown)
		{
			rra(headB);
			i ++;
		}
	}
}

void	ft_push_update(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	pa(headA, headB);
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
}
