/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:55:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/02 13:10:55 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head;
	int		*arr_int;
	int		size;

	if (argc < 2 || argc > 501)
		return (-1);
	size = ft_converter(argc, argv, &arr_int);
	if (size == 0)
	{
		ft_printf("main: Error\n");
		ft_printf("Error\n");
		return (-1);
	}
	head = ft_list_create(arr_int, size);
	if (!head)
		return (-1);
	if (!ft_ops_center(head, size))
	{
		// free head/list?
		return (-1);
	}
	return (0);
}

int ft_converter(int argc, char **argv, int **arr_int)
{
	char	**arr;
	int		size;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (0);
		if (!ft_arg_checker(argc, arr))
			return (0);
		size = ft_arr_atoi(arr_int, argc, arr, 0);
		ft_cleaner(arr);
	}
	else
	{
		if (!ft_arg_checker(argc, argv))
			return (0);
		size = ft_arr_atoi(arr_int, argc, argv, 1);
	}
	return (size);
}

int	ft_arr_atoi(int **arr_int, int argc, char **arr, int flag)
{
	int	size;
	int	error;
	int	i;

	if (flag == 0)
	{
		size = 0;
		while (arr[size])
			size ++;
	}
	else
	{
		size = argc - 1;
		arr ++;
	}
	i = 0;
	*arr_int = malloc(sizeof(int) * size);
	if (!*arr_int)
		return (0);
	while (i < size)
	{
		//ft_printf("ft_arr_atoi: arr[%i] = %s\n", i, arr[i]); //get rid of this debuging statement
		(*arr_int)[i] = ft_atoi_safe(arr[i], &error);
		if (error)
			return (0);
		i ++;
	}
	return (size);
}

void	ft_cleaner(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}
