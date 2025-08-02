/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:23:47 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/02 13:12:45 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../lib/libft/include/libft.h"

//push_swap
int		main(int argc, char **argv);
int 	ft_converter(int argc, char **argv, int **arr_int);
int		ft_arr_atoi(int **arr_int, int argc, char **arr, int flag);
void	ft_cleaner(char **arr);
//ft_arg_checker
int		ft_arg_checker(int argc, char **arr);
int		ft_isntdup(int argc, char **arr);
//ft_list_create
t_list	*ft_list_create(int *arr, int size);
//ft_ops_center
int		ft_ops_center(t_list *head, int size);
int		ft_is_sorted(t_list *head);
//ft_3_stack
int		ft_3stack(t_list *head, int size);
void	ft_3_update_cont(t_list *head, int *arr_cont);
//ft_3_utils
int		ft_3_first_smallest(int cont1, int cont2, int cont3);
int		ft_3_first_largest(int cont1, int cont2, int cont3);
int		ft_3_third_smallest(int cont1, int cont2, int cont3);
int		ft_3_islarger(int cont1, int cont2);
//ft_instructions
void	sa(t_list **list);
void	ra(t_list **list);
void	rra(t_list **list);
#endif
