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

// ============ STACK ============

void	stack_clear(t_stack **stack);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);

// ============ MOVES ============

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void    sa(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack);
void    rra(t_stack **stack_a);

#endif
