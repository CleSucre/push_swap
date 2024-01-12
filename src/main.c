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

static char     *ft_pre_atoi(const char *str)
{
        long int        res;
        int                        is_n;

        while (ft_isspace(*str))
                str++;
        is_n = 0;
        if (*str == '-' || *str == '+')
                if (*str++ == '-')
                        is_n = 1;
        res = 0;
        while (ft_isdigit(*str))
                res = res * 10 + (*str++ - '0');
        str--;
        if (res == 0 && *str != '0')
                return (NULL);
        if (is_n)
                res *= -1;
        return (ft_itoa(res));
}

int     main(int argc, char **argv)
{
        char    *tmp;
        int     i;
        t_stack *stack_a;
        t_stack *stack_b;

        i = 1;
        while (argv[i])
        {
                tmp = ft_pre_atoi(argv[i]);
                if (tmp == NULL)
                {
                        free(tmp);
                        ft_printf("%sError at argument %d\n", RED, i);
                        return (1);
                }
                free(tmp);
                i++;
        }
        i = 1;
        while (argv[i])
        {
                if (i == 1)
                        stack_a = ft_stacknew(ft_atoi(argv[i]));
                else
                        ft_stackadd(&stack_a, ft_stacknew(ft_atoi(argv[i])));
                i++;
        }
        stack_b = NULL;
        ft_push_swap(stack_a, stack_b, argc - 1);
        ft_stackdel(&stack_a);
        ft_stackdel(&stack_b);
        return (0);
}
