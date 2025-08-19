/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:03:34 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 11:07:36 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_arg_checker(int size, char **arr)
{
	int	i;
	int	j;
	int	sign_count;

	i = 0;
	while (i < size)
	{
		sign_count = 0;
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]) && arr[i][j] != ' ' && arr[i][j] != '-')
				return (0);
			if (arr[i][j] == '-')
				sign_count ++;
			if (sign_count > 1)
				return (0);
			j ++;
		}
		i ++;
	}
	if (ft_isntdup(size, arr))
		return (0);
	return (1);
}

int	ft_isntdup(int size, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (!ft_strcmp(arr[i], arr[j]))
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}
