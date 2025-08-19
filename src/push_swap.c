/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:55:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/19 11:43:24 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**arr;
	int		size;

	if (argc < 2 || argc > 501)
		return (-1);
	size = argc - 1;
	if (size == 1)
	{
		if (argv[1][0] == '\0')
			return (-1);
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (-1);
	}
	else
	{
		arr = ft_arr_str(size, argv);
		if (!arr)
			return (-1);
	}
	if (!ft_manager(ft_count_words(arr), arr))
		return (ft_clean_arr_str(ft_count_words(arr), arr), -1);
	ft_clean_arr_str(ft_count_words(arr), arr);
	return (0);
}

int	ft_manager(int size, char **arr)
{
	int		*arr_int;

	if (!ft_arg_checker(size, arr))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (0);
	}
	arr_int = ft_arr_atoi(size, arr);
	if (!arr_int)
		return (0);
	if (!ft_ops_stack(arr_int, size))
	{
		free(arr_int);
		return (0);
	}
	free(arr_int);
	return (1);
}

char	**ft_arr_str(int size, char **argv)
{
	char	**arr;
	int		i;
	int		j;

	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	argv ++;
	i = 0;
	while (i < size)
	{
		arr[i] = malloc(sizeof(char) * (ft_strlen(argv[i]) + 1));
		if (!arr[i])
			return (ft_clean_arr_str(i, arr), NULL);
		j = 0;
		while (argv[i][j])
		{
			arr[i][j] = argv[i][j];
			j ++;
		}
		arr[i][j] = '\0';
		i ++;
	}
	arr[i] = NULL;
	return (arr);
}

int	*ft_arr_atoi(int size, char **arr)
{
	int	*arr_int;
	int	error;
	int	i;

	arr_int = malloc(sizeof(int) * size);
	if (!arr_int)
		return (0);
	i = 0;
	while (i < size)
	{
		arr_int[i] = ft_atoi_safe(arr[i], &error);
		if (error)
		{
			ft_dprintf(STDERR_FILENO, "Error\n");
			free (arr_int);
			return (0);
		}
		i ++;
	}
	return (arr_int);
}

int	ft_count_words(char **arr)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (arr[i])
	{
		words ++;
		i ++;
	}
	return (words);
}
