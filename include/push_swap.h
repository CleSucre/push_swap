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

typedef struct	s_stack
{
        int		value;
        struct s_stack	*next;
}				t_stack;

void     ft_push_swap(t_stack *stack_a, t_stack *stack_b, int size);

t_stack *ft_stacknew(int value);
void    ft_stackadd(t_stack **stack, t_stack *new);
void    ft_stackdel(t_stack **stack);;

int     sa(t_stack *stack);
int     sb(t_stack *stack);
int     ss(t_stack *stack_a, t_stack *stack_b);
int     pa(t_stack *stack_a, t_stack *stack_b);
int     pb(t_stack *stack_a, t_stack *stack_b);
int     ra(t_stack *stack);
int     rb(t_stack *stack);
int     rr(t_stack *stack_a, t_stack *stack_b);
int     rra(t_stack *stack);
int     rrb(t_stack *stack);
int     rrr(t_stack *stack_a, t_stack *stack_b);

#endif
