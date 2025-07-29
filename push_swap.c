/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:55:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/07/29 12:39:50 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 501)
	{
		ft_printf("main: Enter space-separated int set (n<=500)\n");
		return (-1);
	}
	if (!ft_converter(argc, argv))
		return (-1);
	return (0);
}

int ft_converter(int argc, char **argv)
{
	char	**arr;
	int		*arr_int;

	if (!ft_arg_checker(argc, argv))
		return (ft_printf("ft_manager: Enter space-separated int set (n <= 500)\n"), 0);
	arr_int = NULL;
	if (argc == 2)
	{
		ft_printf("ft_manager: argv[1][0] == %c\n", argv[1][0]);
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (0);
		ft_printf("ft_manager: ft_split returns:\n");
		int i = 0;
		while (arr[i])
			ft_printf("%s\n", arr[i++]);
		ft_arr_atoi(&arr_int, argc, arr, 0);	
		ft_cleaner(arr);
	}
	else
		ft_arr_atoi(&arr_int, argc, argv, 1);
	free (arr_int);
	return (1);	
}

int	ft_arg_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '-')
		 		return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

void	ft_arr_atoi(int **arr_int, int argc, char **arr, int flag)
{
	int	size;
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
		return ;
	while (i < size)
	{
		(*arr_int)[i] = ft_atoi(arr[i]);
		ft_printf("ft_arg_converter: arr_int size=%i:\n", i);
		ft_printf("with ft_atoi, arr_int[%i] = arr[%i] = %i = %s\n", i, i, (*arr_int)[i], arr[i]);
		i ++;
	}
}

void	ft_cleaner(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}
