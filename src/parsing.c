#include "push_swap.h"

static char    *ft_pars_one(const char *str)
{
        int     i;
        char    *pre_res;
        char    *tmp;
        char    **split_res;

        if (ft_str_count_chars(str, WHITESPACES) != 0)
        {
                split_res = ft_split(str, ' ');
                if (split_res == NULL)
                        return (NULL);
                i = 0;
                while (split_res[i])
                {

                        tmp = ft_pars_one(split_res[i]);
                        if (tmp == NULL)
                        {
                                ft_free_tab(split_res);
                                return (NULL);
                        }
                        pre_res = ft_strjoin(pre_res, tmp);
                        free(tmp);
                        tmp = pre_res;
                        pre_res = ft_strjoin(pre_res, " ");
                        free(tmp);
                        i++;
                }
                ft_free_tab(split_res);
                return (pre_res);
        }
        return (ft_pre_parsing(str));
}

char     *ft_pre_parsing(const char *input)
{
        long int        res;
        int                        is_n;

        while (ft_isspace(*input))
                input++;
        is_n = 0;
        if (*input == '-' || *input == '+')
                if (*input++ == '-')
                        is_n = 1;
        res = 0;
        while (ft_isdigit(*input))
        {
                res = res * 10 + (*input++ - '0');
                if (res > INT_MAX || res < INT_MIN)
                        return (NULL);
        }
        input--;
        if (res == 0 && *input != '0')
                return (NULL);
        if (is_n)
                res *= -1;
        return (ft_itoa(res));
}

char    **ft_parsing(const char **inputs)
{
        char    *pre_res;
        char    **res;
        char    *tmp;
        char    *tmp2;
        int     i;

        pre_res = malloc(sizeof(char));
        if (pre_res == NULL)
                return (NULL);
        pre_res[0] = '\0';
        i = 1;
        while (inputs[i])
        {
                tmp = ft_pars_one(inputs[i]);
                if (tmp == NULL)
                {
                        ft_printf("Error during parsing\nNumber \"%s\" is not valid\n", inputs[i]);
                        exit(0);
                }
                else
                {
                        tmp2 = ft_strjoin(pre_res, tmp);
                        free(pre_res);
                        pre_res = ft_strjoin(tmp2, " ");
                        free(tmp2);
                }
                free(tmp);
                i++;
        }
        res = ft_split(pre_res, ' ');
        free(pre_res);
        return (res);
}