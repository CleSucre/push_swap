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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc == 1)
		return (1);
	stack_a = ft_parsing((const char **)argv + 1, NULL);
	if (stack_a == NULL)
	{
		ft_fprintf(2, "Error\n");
		return (2);
	}
	stack_b = NULL;
	size = stack_size(stack_a);
	if (size <= 3)
		tiny_sort(&stack_a);
	else if (size <= 5 && !is_sorted(stack_a))
		small_sort(&stack_a, &stack_b);
	else if (size <= 30)
		medium_sort(&stack_a, &stack_b);
	else if (!is_sorted(stack_a))
		radix_sort(&stack_a, &stack_b);
	stack_clear(&stack_a);
	return (0);
}
