/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:23:47 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/16 12:43:41 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../lib/libft/include/libft.h"

# define STDERR_FILENO 2

typedef struct s_stack
{
	int		size;
	double	median;
	int		min_val;
	int		max_val;
	int		min_index;
	int		max_index;
	int		min_content;
	int		max_content;
	int		min_dif;
	int		Awin; //index of A winner
	int		Bwin; //index of B winner
	int		Aup; //number of movements to rotate Aup 
	int		Adown; //number of movements to rotate Adown
	int		Bup; //number of movements to rotate Bup 
	int		Bdown; //number of movements to rotate Bdown
	int		cost_win; //cost of winner movement before every push A to B.
	int		flag; //1=total_up, 2=total_down, 3=total_updown
}t_stack;

//push_swap
int		main(int argc, char **argv);
char	**ft_arr_str(int size, char **argv);
int		ft_manager(int size, char **arr);
int		*ft_arr_atoi(int size, char **arr);
//ft_arg_checker
int		ft_arg_checker(int size, char **arr);
int		ft_isntdup(int size, char **arr);
//ft_list_create
t_list	*ft_list_create(int *arr, int size);
//ft_ops_stack
int		ft_ops_stack(int *arr_int, int size);
int		ft_is_sorted(t_list *head);
//ft_3_stack
void	ft_3stack(t_list **head, int size);
void	ft_3_update_cont(t_list *head, int *arr_cont);
//ft_3_utils
int		ft_3_first_smallest(int cont1, int cont2, int cont3);
int		ft_3_first_largest(int cont1, int cont2, int cont3);
int		ft_3_third_smallest(int cont1, int cont2, int cont3);
int		ft_3_islarger(int cont1, int cont2);
//ft_big_stack
void	ft_big_stack(t_list **headA);
void	ft_big_rotator(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo);
void	ft_big_rotator_flag1(t_list **headA, t_list **headB, t_stack *t_Ainfo);
void	ft_big_rotator_flag2(t_list **headA, t_list **headB, t_stack *t_Ainfo);
void	ft_big_rotator_flag3(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo);
void	ft_push_update(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo);
//ft_big_info
void	ft_update_info(t_list *headA, t_list *headB, t_stack *t_Ainfo, t_stack *t_Binfo);
void	ft_stack_info(t_list *head, t_stack *stack_info);
void	ft_node_info(t_list *head, t_stack *stack_info);
void	ft_cost_info(t_list *headA, t_list *headB, t_stack *t_Ainfo, t_stack *t_Binfo);
//ft_big__info_utils
void	ft_A_min_in_B(t_list *currentA, t_list *currentB, t_stack *t_Ainfo, t_stack *t_Binfo);
void	ft_A_other_in_B(t_list *currentA, t_list *currentB, t_stack *t_Ainfo);
void	ft_matchB(t_list *currentA, t_list *currentB, t_stack *t_Ainfo);
void	ft_info_winner(t_list *currentA, t_stack *t_Ainfo);
void	ft_cost_flag(t_list *currentA, t_list *currentB);
int		ft_eq_larger(int n1, int n2);
void	ft_choice(t_list *currentA);
//ft_Asize_is_3
void	ft_Asize_is_3(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo);
void	ft_Asize_is_3_rotator(t_list **headA, t_list **headB, t_stack *t_Ainfo, t_stack *t_Binfo);
//ft_instructions
void	sa(t_list **list);
void	ra(t_list **list);
void	rra(t_list **list);
//ft_instructions2
void	ss(t_list **listA, t_list **listB);
void	rr(t_list **listA, t_list **listB);
void	rrr(t_list **listA, t_list **listB);
void	pa(t_list **list_from, t_list **list_to);
//ft_clean
void	ft_clean_list(t_list **head);
void	del(void *content);
void	ft_clean_arr_str(int pos, char **arr);

#endif
