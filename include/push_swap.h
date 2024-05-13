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

int		is_sorted(t_stack *stack);

// ============ PUSH_SWAP ============

void	push_swap(t_stack **stack_a, t_stack **stack_b);

// ============ PARSING ============

t_stack	*ft_parsing(const char **argv, t_stack *stack);

// ============ MOVES ============

void	stack_clear(t_stack **stack);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_max(t_stack *stack);

// ============ SHIFT ============

void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// ============ SWAP ============

void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

// ============ PUSH ============

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **top, int value);

#endif
