/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:59:40 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/02 10:13:22 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_3_first_smallest(int cont1, int cont2, int cont3)
{
	if (cont1 < cont2 && cont1 < cont3)
		return (1);
	return (0);
}

int	ft_3_first_largest(int cont1, int cont2, int cont3)
{
	if (cont1 > cont2 && cont1 > cont3)
		return (1);
	return (0);
}

int	ft_3_third_smallest(int cont1, int cont2, int cont3)
{
	if (cont3 < cont2 && cont3 < cont1)
		return(1);
	return (0);
}

int	ft_3_islarger(int cont1, int cont2)
{
	if (cont1 > cont2)
		return (1);
	return (0);
}
