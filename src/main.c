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

void    ft_free_tab(char **tab)
{
        int     i;

        i = 0;
        while (tab[i])
                free(tab[i++]);
        free(tab);
}

int     main(int argc, char **argv)
{
        char    *tmp;
        char    *input;
        char    **output;
        int     i;
        t_list *stack_a;
        t_list *stack_b;

        if (argc == 1)
                return (0);
        output = ft_parsing((const char **)argv);

        i = 0;
        while (output[i])
        {
                ft_printf("output[%d] = %s\n", i, output[i]);
                i++;
        }

        // ft_push_swap(stack_a, stack_b, argc - 1);

        ft_free_tab(output);
        return (0);
}
