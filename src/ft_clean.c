/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:44:58 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/18 12:57:13 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_clean_list(t_list **head)
{
	ft_lstclear(head, &del);
}

void	del(void *content)
{
	if (content)
		*(int *)content = 0;
}

void	ft_clean_arr_str(int pos, char **arr)
{
	int	i;

	i = pos - 1;
	while (i >= 0)
	{
		free (arr[i]);
		i --;
	}
	free (arr);
}
