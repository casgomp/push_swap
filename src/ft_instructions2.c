/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:07:41 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 13:09:18 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ra(t_list **list)
{
	rotate(list);
	ft_printf("ra\n");
}

void	rb(t_list **list)
{
	rotate(list);
	ft_printf("rb\n");
}

void	rra(t_list **list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
}

void	rrb(t_list **list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}
