/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:23:35 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/07 11:20:50 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_big_stack(t_list **head, int size)
{
	//size is passed so i can calculate median already, create index, assign half.
	t_list	*stackB;
	int		median;

	median = size;
	stackB = NULL;
	pa(head, &stackB);
	pa(head, &stackB);
}
