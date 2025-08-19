/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asize_is_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:57:47 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 12:30:56 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h" 

void	ft_asize_is_3(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	if (!ft_is_sorted(*heada))
		ft_3stack(heada, t_ainfo->size);
	if (t_binfo->size == 2)
	{
		if (ft_is_sorted(*headb))
			sb(headb);
	}
	ft_update_info(*heada, *headb, t_ainfo, t_binfo);
	while (*headb)
	{
		ft_update_info(*heada, *headb, t_ainfo, t_binfo);
		ft_asize_is_3_awin(*heada, *headb, t_ainfo);
		if (t_ainfo->min_dif < INT_MAX)
			ft_asize_is_3_rotator(heada, headb, t_ainfo, t_binfo);
		else
			ft_asize_is_3_blarger(heada, t_ainfo);
		pa(headb, heada);
	}
	ft_update_info(*heada, *headb, t_ainfo, t_binfo);
	if (*(int *)(*heada)->content != t_ainfo->min_val)
	{
		while (*(int *)(*heada)->content != t_ainfo->min_val)
			rra(heada);
	}
}

void	ft_asize_is_3_awin(t_list *heada, t_list *headb, t_stack *t_ainfo)
{
	t_list	*currenta;
	int		result;

	t_ainfo->min_dif = INT_MAX;
	currenta = heada;
	while (currenta)
	{
		result = *(int *)currenta->content - *(int *)(headb)->content;
		if (result > 0 && result < t_ainfo->min_dif)
		{
			t_ainfo->min_dif = result;
			t_ainfo->awin = currenta->index;
		}
		currenta = currenta->next;
	}
}

void	ft_asize_is_3_rotator(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo)
{
	if (t_ainfo->awin <= t_ainfo->median)
	{
		while (*headb && ((*(int *)(*heada)->content
				- *(int *)(*headb)->content) != t_ainfo->min_dif))
		{
			ra(heada);
			ft_update_info(*heada, *headb, t_ainfo, t_binfo);
		}
	}
	else
	{
		while ((*headb && (*(int *)(*heada)->content 
				- *(int *)(*headb)->content) != t_ainfo->min_dif))
		{
			rra(heada);
			ft_update_info(*heada, *headb, t_ainfo, t_binfo);
		}
	}
}

void	ft_asize_is_3_blarger(t_list **heada, t_stack *t_ainfo)
{
	if (t_ainfo->min_index <= t_ainfo->median)
	{
		while (*(int *)(*heada)->content != t_ainfo->min_content)
			ra(heada);
	}
	else
	{
		while (*(int *)(*heada)->content != t_ainfo->min_content)
			rra(heada);
	}
}
