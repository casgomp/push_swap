/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:23:35 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 12:27:23 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_big_stack(t_list **heada)
{
	t_list	*headb;
	t_stack	t_ainfo;
	t_stack	t_binfo;

	headb = NULL;
	ft_update_info(*heada, headb, &t_ainfo, &t_binfo);
	if (t_ainfo.size <= 5)
	{
		while (t_ainfo.size > 3)
			ft_push_update(heada, &headb, &t_ainfo, &t_binfo);
		ft_asize_is_3(heada, &headb, &t_ainfo, &t_binfo);
	}
	else
		ft_big_stack_bigger(heada, &headb, &t_ainfo, &t_binfo);
}

void	ft_big_rotator(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	if (t_ainfo->flag == 1)
		ft_big_rotator_flag1(heada, headb, t_ainfo);
	else if (t_ainfo->flag == 2)
		ft_big_rotator_flag2(heada, headb, t_ainfo);
	else if (t_ainfo->flag == 3)
		ft_big_rotator_flag3(heada, headb, t_ainfo, t_binfo);
}

void	ft_big_rotator_flag1(t_list **heada, t_list **headb, t_stack *t_ainfo)
{
	int	dif;

	if (t_ainfo->aup < t_ainfo->bup)
	{
		ft_big_rotator_op2(t_ainfo->aup, heada, headb, rr);
		dif = t_ainfo->bup - t_ainfo->aup;
		ft_big_rotator_op1(dif, headb, rb);
	}
	else
	{
		ft_big_rotator_op2(t_ainfo->bup, heada, headb, rr);
		dif = t_ainfo->aup - t_ainfo->bup;
		ft_big_rotator_op1(dif, heada, ra);
	}
}

void	ft_big_rotator_flag2(t_list **heada, t_list **headb, t_stack *t_ainfo)
{
	int	dif;

	if (t_ainfo->adown < t_ainfo->bdown)
	{
		ft_big_rotator_op2(t_ainfo->adown, heada, headb, rrr);
		dif = t_ainfo->bdown - t_ainfo->adown;
		ft_big_rotator_op1(dif, headb, rrb);
	}
	else
	{
		ft_big_rotator_op2(t_ainfo->bdown, heada, headb, rrr);
		dif = t_ainfo->adown - t_ainfo->bdown;
		ft_big_rotator_op1(dif, heada, rra);
	}
}

void	ft_big_rotator_flag3(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	if (t_ainfo->awin <= t_ainfo->median)
		ft_big_rotator_op1(t_ainfo->aup, heada, ra);
	else
		ft_big_rotator_op1(t_ainfo->adown, heada, rra);
	if (t_ainfo->bwin <= t_binfo->median)
		ft_big_rotator_op1(t_ainfo->bup, headb, rb);
	else
		ft_big_rotator_op1(t_ainfo->bdown, headb, rrb);
}
