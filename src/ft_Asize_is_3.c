/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Asize_is_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:57:47 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 10:25:39 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h" 

void	ft_Asize_is_3(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	//ft_printf("ft_Asize_is_3\n");
	t_list *currentA;
	int	result;
	
	if(!ft_is_sorted(*headA))
	{
		//ft_printf("ft_Asize_is_3: call to ft_3stack\n");
		ft_3stack(headA, t_Ainfo->size);
	}
	if (t_Binfo->size == 2)
	{
		//ft_printf("ft_Asize_is_3: t_B size=%i\n", t_Binfo->size);
		if (ft_is_sorted(*headB))
			sb(headB);//sa(headB);
	}
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
	while (*headB) //loop in another function?
	{
		ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
		t_Ainfo->min_dif = INT_MAX;
		currentA = *headA;
		while(currentA)
		{
			result = *(int *)currentA->content - *(int *)(*headB)->content;
			//ft_printf("ft_Asize_is_3: result = %i - %i\n", *(int *)currentA->content, *(int*)(*headB)->content);
			if (result > 0 && result < t_Ainfo->min_dif)
			{
				t_Ainfo->min_dif = result;
				t_Ainfo->Awin = currentA->index;
				//ft_printf("ft_Asize_is_3: A min_dif=%i\n", t_Ainfo->min_dif);
			}
			currentA = currentA->next;
		}
		if (t_Ainfo->min_dif < INT_MAX)
			ft_Asize_is_3_rotator(headA, headB, t_Ainfo, t_Binfo);
		else
		{
			if (t_Ainfo->min_index <= t_Ainfo->median)
			{
				while (*(int *)(*headA)->content != t_Ainfo->min_content)
					ra(headA);
			}
			else
			{
				while (*(int *)(*headA)->content != t_Ainfo->min_content)
					rra(headA);
			}
		}
		pa(headB, headA);//pa(headB, headA);
	}
	ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
	//if min_val not at index 1, then rotate until it is. (maybe could use
	//a function used to calculate cost fo knwing if its better to rotate
	//ra or rra. In the meantime I'll assume best way is always rra:
	if (*(int *)(*headA)->content != t_Ainfo->min_val)
	{	
		while (*(int *)(*headA)->content != t_Ainfo->min_val)
			rra(headA);
	}
/*	//debugging loop:............................................................................debugging loop
	t_list *current = *headA;
	int i = 0;
	while (current)
	{
		ft_printf("sorted list stackA, index[%i] = %i\n", i, *(int *)current->content);
		i ++;
		current = current->next;
	}
	//debugging loop:............................................................................debugging loop /*/
}

void	ft_Asize_is_3_rotator(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo)
{
	if (t_Ainfo->Awin <= t_Ainfo->median)
		{
			while (*headB && ((*(int *)(*headA)->content - *(int *)(*headB)->content) != t_Ainfo->min_dif))
			{
				//ft_printf("ft_Asize_is_3_rotator: ra comes from here\n");
				ra(headA);
				ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
			}
		}
	else
		{
			while ((*headB && (*(int *)(*headA)->content - *(int *)(*headB)->content) != t_Ainfo->min_dif))
			{
				//ft_printf("ft_Asize_is_3_rotator: rra comes from here\n");
				//ft_printf("ft_Asize_is_3_rotator: A min_dif=%i\n", t_Ainfo->min_dif);
				rra(headA);
				ft_update_info(*headA, *headB, t_Ainfo, t_Binfo);
			}
		}
}
