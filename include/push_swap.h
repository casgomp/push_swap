/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:23:47 by pecastro          #+#    #+#             */
/*   Updated: 2025/08/21 16:18:28 by pecastro         ###   ########.fr       */
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
	int		awin;
	int		bwin;
	int		aup; 
	int		adown;
	int		bup;
	int		bdown;
	int		cost_win;
	int		flag;
}t_stack;
//awin: index of A winner
//bwin: index of B winner
//aup: number of movements to rotate Aup 
//adown: number of movements to rotate Adown
//bup: number of movements to rotate Bup 
//bdown: number of movements to rotate Bdown
//cost_win: cost of winner movement before every push A to B.
//flag: 1=total_up, 2=total_down, 3=total_updown

//push_swap
int		main(int argc, char **argv);
char	**ft_arr_str(int size, char **argv);
int		ft_manager(int size, char **arr);
int		*ft_arr_atoi(int size, char **arr);
int		ft_count_words(char **arr);
//ft_arg_checker
int		ft_arg_checker(int size, char **arr);
int		ft_isntdup(int size, int *arr_int);
//ft_list_create
t_list	*ft_list_create(int *arr, int size);
//ft_ops_stack
int		ft_ops_stack(int *arr_int, int size);
int		ft_is_sorted(t_list *head);
//ft_3_stack
void	ft_3stack(t_list **head, int size);
void	ft_3_ops_and_update(t_list **head, int *arr_cont, void (*f)(t_list **));
void	ft_3_update_cont(t_list *head, int *arr_cont);
//ft_3_utils
int		ft_3_first_smallest(int cont1, int cont2, int cont3);
int		ft_3_first_largest(int cont1, int cont2, int cont3);
int		ft_3_third_smallest(int cont1, int cont2, int cont3);
int		ft_3_islarger(int cont1, int cont2);
//ft_big_stack
void	ft_big_stack(t_list **heada);
void	ft_big_rotator(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
void	ft_big_rotator_flag1(t_list **heada, t_list **headb, t_stack *t_ainfo);
void	ft_big_rotator_flag2(t_list **heada, t_list **headb, t_stack *t_ainfo);
void	ft_big_rotator_flag3(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
//ft_big_stack_utils
void	ft_big_stack_bigger(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
void	ft_big_rotator_op1(int val, t_list **head, void (*f)(t_list**));
void	ft_big_rotator_op2(int val, t_list **heada, t_list **headb, 
			void (*f)(t_list**, t_list**));
void	ft_push_update(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
void	ft_rotate_find(t_list **headb, t_stack t_binfo);
//ft_big_info
void	ft_update_info(t_list *heada, t_list *headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
void	ft_stack_info(t_list *head, t_stack *stack_info);
void	ft_stack_info_loop(t_list *head, t_stack *stack_info);
void	ft_node_info(t_list *head, t_stack *stack_info);
void	ft_cost_info(t_list *heada, t_list *headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
//ft_big__info_utils
void	ft_a_min_in_b(t_list *currenta, t_list *currentb, t_stack *t_binfo);
void	ft_a_other_in_b(t_list *currenta, t_list *currentb);
void	ft_matchb(t_list *currenta, t_list *currentb);
void	ft_info_winner(t_list *currenta, t_stack *t_ainfo);
void	ft_cost_flag(t_list *currenta, t_list *currentb);
//ft_big_info_utils2
int		ft_eq_larger(int n1, int n2);
void	ft_choice(t_list *currenta);
//ft_Asize_is_3
void	ft_asize_is_3(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
void	ft_asize_is_3_awin(t_list *heada, t_list *headb, t_stack *t_ainfo);
void	ft_asize_is_3_blarger(t_list **heada, t_stack *t_ainfo);
void	ft_asize_is_3_rotator(t_list **heada, t_list **headb, 
			t_stack *t_ainfo, t_stack *t_binfo);
//ft_instructions
void	sa(t_list **list);
void	sb(t_list **list);
//ft_instructions2
void	ra(t_list **list);
void	rb(t_list **list);
void	rra(t_list **list);
void	rrb(t_list **list);
//ft_instructions3
void	ss(t_list **listA, t_list **listB);
void	rr(t_list **listA, t_list **listB);
void	rrr(t_list **listA, t_list **listB);
void	pa(t_list **list_from, t_list **list_to);
void	pb(t_list **list_from, t_list **list_to);
//ft_instructions4
void	swap(t_list **list);
void	rotate(t_list **list);
void	reverse_rotate(t_list **list);
//ft_clean
void	ft_clean_list(t_list **head);
void	del(void *content);
void	ft_clean_arr_str(int pos, char **arr);

#endif
