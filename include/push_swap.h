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

// ============ GOD_SORT ============

void	god_sort(t_stack **stack_a, t_stack **stack_b);

// ============ SMALL_SORT ============

void	tiny_sort(t_stack **stack_a);
void	small_sort(t_stack **stack_a, t_stack **stack_b);
void	medium_sort(t_stack **stack_a, t_stack **stack_b);

// ============ P_MOVES ============

void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);

// ============ R_MOVES ============

void	rb(t_stack **stack_b);
void	ra(t_stack **stack);
void	rra(t_stack **stack_a);

// ============ S_MOVES ============

void	sa(t_stack **stack_a);

// ========== STACK_SIZE ==========

int		stack_size(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);

// ============ STACK_UTILS ============

void	*stack_clear(t_stack **stack);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
int		is_sorted(t_stack *stack);

// ============ PARSING ============

t_stack	*ft_parsing(const char **argv, t_stack *stack);

#endif
