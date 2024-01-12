#include "push_swap.h"

t_stack *ft_stacknew(int value)
{
        t_stack *new;

        new = malloc(sizeof(t_stack));
        if (!new)
                return (NULL);
        new->value = value;
        new->next = NULL;
        return (new);
}

void    ft_stackadd(t_stack **stack, t_stack *new)
{
        new->next = *stack;
        *stack = new;
}

void    ft_stackdel(t_stack **stack)
{
        t_stack *tmp;

        while (*stack)
        {
                tmp = (*stack)->next;
                free(*stack);
                *stack = tmp;
        }
}