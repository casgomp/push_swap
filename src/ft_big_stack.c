/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:23:35 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 09:41:09 by pecastro         ###   ########.fr       */
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
	if (t_Ainfo.size <= 5)
	{
		while (t_Ainfo.size > 3)
			ft_push_update(headA, &headB, &t_Ainfo, &t_Binfo);
		ft_Asize_is_3(headA, &headB, &t_Ainfo, &t_Binfo);
	}
	else
		ft_big_stack_bigger(headA, &headB, &t_Ainfo, &t_Binfo);
	//ft_clean_list(&headB); //redundant? At this point all B members are in A and headB is pointing at NULL.
}

void	ft_big_rotator(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	if (t_Ainfo->flag == 1)
		ft_big_rotator_flag1(headA, headB, t_Ainfo);
	else if (t_Ainfo->flag == 2)
		ft_big_rotator_flag2(headA, headB, t_Ainfo);
	else if (t_Ainfo->flag == 3)
		ft_big_rotator_flag3(headA, headB, t_Ainfo, t_Binfo);
}

void	ft_big_rotator_flag1(t_list **headA, t_list **headB, t_stack *t_Ainfo)
{
	int	dif;

	if (t_Ainfo->Aup < t_Ainfo->Bup)
	{
		ft_big_rotator_op2(t_Ainfo->Aup, headA, headB, rr);
		dif = t_Ainfo->Bup - t_Ainfo->Aup;
  		ft_big_rotator_op1(dif, headB, rb);
	}
	else
	{
		ft_big_rotator_op2(t_Ainfo->Bup, headA, headB, rr);
		dif = t_Ainfo->Aup - t_Ainfo->Bup;
		ft_big_rotator_op1(dif, headA, ra);
	}
}

void	ft_big_rotator_flag2(t_list **headA, t_list **headB, t_stack *t_Ainfo)
{
	int	dif;

	if (t_Ainfo->Adown < t_Ainfo->Bdown)
	{
		ft_big_rotator_op2(t_Ainfo->Adown, headA, headB, rrr);
		dif = t_Ainfo->Bdown - t_Ainfo->Adown;
  		ft_big_rotator_op1(dif, headB, rrb);
	}
	else
	{
		ft_big_rotator_op2(t_Ainfo->Bdown, headA, headB, rrr);
		dif = t_Ainfo->Adown - t_Ainfo->Bdown;
   		ft_big_rotator_op1(dif, headA, rra);
	}
}

void	ft_big_rotator_flag3(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	if (t_Ainfo->Awin <= t_Ainfo->median)
		ft_big_rotator_op1(t_Ainfo->Aup, headA, ra);
	else
		ft_big_rotator_op1(t_Ainfo->Adown, headA, rra);
	if (t_Ainfo->Bwin <= t_Binfo->median)
		ft_big_rotator_op1(t_Ainfo->Bup, headB, rb);
	else
		ft_big_rotator_op1(t_Ainfo->Bdown, headB, rrb);
}
