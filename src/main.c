/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:09:25 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/12 18:09:25 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Print the stack. For debugging purposes.
 * @param stack
 */
static void	ft_print_stack(t_stack *stack, char name)
{
	int	i;

	i = 0;
	while (stack)
	{
		ft_printf("stack_%c[%d] = %d\n", name, i, stack->value);
		stack = stack->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
    t_stack *stack_b;

	if (argc == 1)
		return (1);
	stack_a = ft_parsing((const char **)argv + 1, NULL);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
		return (2);
	}
    stack_b = NULL;
    ft_print_stack(stack_a, 'a');
    push_swap(&stack_a, &stack_b);
    ft_print_stack(stack_a, 'a');
	stack_clear(&stack_a);
	return (0);
}
