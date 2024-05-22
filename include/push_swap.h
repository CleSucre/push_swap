/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:38:49 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/11 23:38:49 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/colors.h"
# include <unistd.h>

// ============ STACK ============

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
}						t_stack;

// ============ MAIN ============

int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);
int		is_sorted(t_stack *stack);

// ============ PUSH_SWAP ============

void	tiny_sort(t_stack **stack_a);
void	small_sort(t_stack **stack_a, t_stack **stack_b);
void	medium_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// ============ PARSING ============

t_stack	*ft_parsing(const char **argv, t_stack *stack);

// ============ STACK ============

void	*stack_clear(t_stack **stack);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);

// ============ MOVES ============

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack);
void	rra(t_stack **stack_a);

// ============ BITS ============

int		max_bits(int n);
int		transform(int n, int max_bit, int min_bit);

#endif
