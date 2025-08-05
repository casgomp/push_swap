/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:03:34 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/05 11:40:25 by pecastro         ###   ########.fr       */
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
			{
				//ft_printf("error comes from argchecker isdigit\n");
				return (0);
			}
			if (arr[i][j] == '-')
				sign_count ++;
			if (sign_count > 1)
			{
				//ft_printf("error comes from argchecker signcount\n");
				return (0);
			}
			j ++;
		}
		i ++;
	}
	if (ft_isntdup(size, arr))
	{
		//ft_printf("error comes from argchecker isntdup\n");
		return (0);
	}
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
