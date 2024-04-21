#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "ft_printf.h"
#include "get_next_line.h"

void	swap_a(t_list **stack_a, bool id);
void	swap_b(t_list **stack_b, bool id);
void	push_a(t_list **stack_a, t_list **stack_b, bool id);
void	push_b(t_list **stack_b, t_list **stack_a, bool id);
void	swap_swap(t_list **stack_a, t_list **stack_b, bool id);
void	rotate_a(t_list **stack_a, bool id);
void	rotate_b(t_list **stack_b, bool id);
void	rotate_rotate(t_list **stack_a, t_list **stack_b, bool id);
void	reverse_rotate_a(t_list **stack_a, bool id);
void	reverse_rotate_b(t_list **stack_b, bool id);
void	reverse_rr(t_list **stack_a, t_list **stack_b, bool id);
void	check_args(char **argv, t_list **list);
void	free_double(char **ptr);
void	del(void *ptr);
long	ft_atol(char *var, long res, long signe);
bool	check_duplicate(t_list *list, int number);
bool	is_sorted(t_list *stack_a);

#endif
