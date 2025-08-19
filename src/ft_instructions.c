/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:43:35 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 13:11:49 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sa(t_list **list)
{
	swap(list);
	ft_printf("sa\n");
}

void	sb(t_list **list)
{
	swap(list);
	ft_printf("sb\n");
}
