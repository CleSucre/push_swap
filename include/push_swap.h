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

// ============ MAIN ============

void    ft_free_tab(char **tab);
void    ft_push_swap(t_list *stack_a, t_list *stack_b, int size);

// ============ PARSING ============

char    *ft_pre_parsing(const char *input);
char    **ft_parsing(const char **inputs);

// ============ OPERATIONS ============

int     sa(t_list *stack);
int     sb(t_list *stack);
int     ss(t_list *stack_a, t_list *stack_b);
int     pa(t_list *stack_a, t_list *stack_b);
int     pb(t_list *stack_a, t_list *stack_b);
int     ra(t_list *stack);
int     rb(t_list *stack);
int     rr(t_list *stack_a, t_list *stack_b);
int     rra(t_list *stack);
int     rrb(t_list *stack);
int     rrr(t_list *stack_a, t_list *stack_b);

#endif
