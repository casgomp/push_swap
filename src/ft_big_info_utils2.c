/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_info_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:47:29 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 10:49:33 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

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
