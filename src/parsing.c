#include "push_swap.h"

static t_stack *check_value(const char *str)
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
        if (*str != '\0')
                return (NULL);
        str--;
        if (res == 0 && *str != '0')
                return (NULL);
        if (is_n)
                res *= -1;
        if (res > INT_MAX || res < INT_MIN)
                return (NULL);
        return (stack_new(res));
}

static t_stack *check_duplicates(t_stack *stack)
{
        t_stack *tmp_stack;
        t_stack *tmp_next;

        tmp_stack = stack;
        while (tmp_stack)
        {
                tmp_next = tmp_stack->next;
                while (tmp_next)
                {
                        if (tmp_stack->value == tmp_next->value)
                        {
                                stack_clear(&stack);
                                return (NULL);
                        }
                        tmp_next = tmp_next->next;
                }
                tmp_stack = tmp_stack->next;
        }
        return (stack);
}

t_stack *ft_parsing(const char **argv, t_stack *stack)
{
        t_stack *new_stack;
        char    **values;
        int             i;

        while (*argv)
        {
                values = ft_split(*argv++, WHITESPACES);
                if (values == NULL)
                        return (NULL);
                i = -1;
                while (values[++i])
                {
                        new_stack = check_value(values[i]);
                        if (new_stack == NULL)
                        {
                                ft_free_tab(values);
                                stack_clear(&stack);
                                return (NULL);
                        }
                        stack_add_back(&stack, new_stack);
                }
                ft_free_tab(values);
        }
        return (check_duplicates(stack));
}
