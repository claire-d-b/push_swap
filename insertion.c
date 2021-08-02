/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:20:07 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/02 11:12:11 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    int i;
    char *tmp;

    i = 0;
    tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!tmp)
        return (0);
    while (str[i])
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

int count_el(t_list *stack)
{
    int i;

    i = 0;
    go_to_first_el(&stack);
    while (stack->next)
    {
        stack = stack->next;
        i++;
    }
    return (i + 1);
}

static int	conv_char_int(char str, int k)
{
	k *= 10;
	k += str - 48;
	return (k);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		k = conv_char_int(str[i], k);
		i++;
	}
	if (j % 2 != 0)
		return (k * -1);
	return (k);
}

t_list	*ft_lstnew(void *value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prec = NULL;
	return (new);
}

void    ft_lst_delone(t_list *el)
{
    free(el->value);
    el->value = 0;
    el->next = 0;
    el->prec = 0;
    free(el);
    el = NULL;
}

int init_stacks(t_list **stack_a, t_list **stack_b)
{
    *stack_a = NULL;
    *stack_b = NULL;
    return (0);
}

void    fill_list(t_list *stack_a, char *arg)
{
    int *nb;

    nb = malloc(sizeof(int));
    *nb = ft_atoi(arg);
    stack_a = ft_lstnew(nb);
}

void    ft_lst_addback(t_list **stack, t_list *el)
{
    if (!(*stack))
    {
        *stack = el;
        (*stack)->prec = 0;
        (*stack)->next = 0;
    }
    else
    {
        while ((*stack)->next)
            (*stack) = (*stack)->next;
        (*stack)->next = el;
        el->prec = (*stack);
        *stack = (*stack)->next;
        el->next = NULL;
    }
}

void    ft_lst_addfront(t_list **stack, t_list *el)
{
    while ((*stack)->prec)
        (*stack) = (*stack)->prec;
    if (!(*stack))
        *stack = el;
    el->next = (*stack);
    *stack = el;
    (*stack)->prec = 0;
}

void    init_struct_count(t_count *count, int args_nb)
{
    count->count = 0;
    count->start_nb = args_nb;
    count->stack_a_nb = args_nb;
    count->stack_b_nb = 0;
    count->r_or_rr = 0;
    count->stack_a_idx = 0;
    count->stack_b_idx = 0;
    count->real_index_b = 0;
}

void    go_to_first_el(t_list **stack)
{
    if (*stack)
    {
        while ((*stack)->prec)
            (*stack) = (*stack)->prec;
    }
}

void    go_to_last_el(t_list **stack)
{
    if (*stack)
    {
        while ((*stack)->next)
            (*stack) = (*stack)->next;
    }
}

void    free_stack(t_list *stack)
{
    t_list *tmp;

    tmp = NULL;
    if (stack)
    {
        while (stack->prec)
            stack = stack->prec;
        while (stack->next)
        {
            tmp = stack->next;
            ft_lst_delone(stack);
            stack = tmp;
        }
        ft_lst_delone(stack);
    }
}

void    print_no_details(t_list *stack_a, t_list *stack_b)
{
    if (stack_a)
    {
        while (stack_a->prec)
        stack_a = stack_a->prec;
        while (stack_a->next)
        {
            printf("stack a v %d\n", *(int *)stack_a->value);
            stack_a = stack_a->next;
        }
        printf("stack a v %d\n", *(int *)stack_a->value);
    }
    if (stack_b)
    {
        while (stack_b->prec)
            stack_b = stack_b->prec;
        while (stack_b->next)
        {
            printf("stack b v %d\n", *(int *)stack_b->value);
            stack_b = stack_b->next;
        }
        printf("stack b v %d\n", *(int *)stack_b->value);
    }
}

void    print_stack_a_a_b(t_list *stack_a, t_list *stack_b)
{
    if (stack_a)
    {
        while (stack_a->prec)
        stack_a = stack_a->prec;
        while (stack_a->next)
        {
            printf("stack a v %d\n", *(int*)stack_a->value);
            printf("stack a %d\n", (int)stack_a);
            printf("stack a next %d\n", (int)stack_a->next);
            printf("stack a prec %d\n", (int)stack_a->prec);
            stack_a = stack_a->next;
        }
        printf("stack a v %d\n", *(int*)stack_a->value);
        printf("stack a %d\n", (int)stack_a);
        printf("stack a next %d\n", (int)stack_a->next);
        printf("stack a prec %d\n", (int)stack_a->prec);
    }
    if (stack_b)
    {
        while (stack_b->prec)
            stack_b = stack_b->prec;
        while (stack_b->next)
        {
            printf("stack b v %d\n", *(int*)stack_b->value);
            printf("stack b %d\n", (int)stack_b);
            printf("stack b next %d\n", (int)stack_b->next);
            printf("stack b prec %d\n", (int)stack_b->prec);
            stack_b = stack_b->next;
        }
        printf("stack b v %d\n", *(int*)stack_b->value);
        printf("stack b %d\n", (int)stack_b);
        printf("stack b next %d\n", (int)stack_b->next);
        printf("stack b prec %d\n", (int)stack_b->prec);
    }
}

int find_index(int value, t_list *stack)
{
    int x;
    int start_value;

    x = 0;
    go_to_first_el(&stack);
    start_value = *(int*)stack->value;
    while (stack->next)
    {
        if (value < *(int*)stack->value && value > *(int*)stack->next->value)
            return (x);
        stack = stack->next;
        x++;
    }
    if (value < *(int*)stack->value && value > start_value)
        return (x);
    go_to_first_el(&stack);
    return (-1);
}

int    index_max_el(t_list **stack, int max)
{
    int i;

    i = 0;
    if (*stack)
    {
        go_to_first_el(stack);
        while ((*stack)->next)
        {
            if (*(int*)(*stack)->value == max)
                return (i);
            *stack = (*stack)->next;
            i++;
        }
        go_to_first_el(stack);
    }
    return (i);
}

int find_max(t_list *max)
{
    int max_value;

    go_to_first_el(&max);
    max_value = *(int*)max->value;
    while (max->next)
    {
        if (max_value < *(int*)max->value)
            max_value = *(int*)max->value;
        max = max->next;
    }
    if (max_value < *(int*)max->value)
        max_value = *(int*)max->value;
     go_to_first_el(&max);
    return (max_value);
}

int find_min(t_list *max)
{
    int max_value;

    go_to_first_el(&max);
    max_value = *(int*)max->value;
    while (max->next)
    {
        if (max_value > *(int*)max->value)
            max_value = *(int*)max->value;
        max = max->next;
    }
    if (max_value > *(int*)max->value)
        max_value = *(int*)max->value;
     go_to_first_el(&max);
    return (max_value);
}

void    set_ct_limit(int *ct, t_list **stack_a, t_list *stack_b, t_count *count)
{
    if (*ct == -1 && *(int*)(*stack_a)->value > find_max(stack_b))
    *ct = index_max_el(&stack_b, find_max(stack_b));
    else if (*ct == -1 && *(int*)(*stack_a)->value < find_min(stack_b))
        *ct = index_max_el(&stack_b, find_min(stack_b)) + 1;
    if (*ct > count->stack_b_nb / 2)
        *ct = count->stack_b_nb - *ct;
}

void    set_if_high_or_low(int i, int *k, int *boolean, t_count *count)
{
    if (i > count->stack_a_nb / 2)
    {
        *boolean = 1;
        *k = count->stack_a_nb - i;
    }
    else
    {
        *boolean = 0;
        *k = i;
    }
}

void    init_four_values(int *i, int *k, int *boolean, int *ct)
{
    *i = 0;
    *k = 0;
    *boolean = 0;
    *ct = 0;
}

void    choose_value(t_list **stack_a, t_list *stack_b, t_count *count)
{
    int i;
    int ct;
    int comp;
    int k;
    int boolean;

    init_four_values(&i, &k, &boolean, &ct);
    while (i < count->stack_a_nb)
    {
        ct = find_index(*(int *)(*stack_a)->value, stack_b);
        count->real_index_b = ct;
        set_ct_limit(&ct, stack_a, stack_b, count);
        set_if_high_or_low(i, &k, &boolean, count);
        if (ct + k < comp || i == 0)
        {
            comp = ct + k;
            count->stack_a_idx = k;
            count->r_or_rr = boolean;
            count->stack_b_idx = count->real_index_b;
        }
        if (i < count->stack_a_nb - 1)
            *stack_a = (*stack_a)->next;
        i++;
    }
}

int is_max(int lst, int max)
{
    if (lst == max)
        return (1);
    return (0);
}

int ra_o_rra(t_list *s_lst, int max)
{
    int i;
    
    i = 0;
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        if (*(int*)s_lst->value == max)
            return (i);
        s_lst = s_lst->next;
        i++;
    }
    return (i);
}

int checker_max(t_list *s_lst)
{
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        if (s_lst->value > s_lst->next->value)
            return (0);
        s_lst = s_lst->next;
    }
    return (1);
}

int checker_min(t_list *s_lst)
{
    while (s_lst->next)
    {
        if (*(int *)s_lst->value > *(int *)(s_lst->next->value))
            return (0);
        s_lst = s_lst->next;
    }
    return (1);
}

int find_biggest_gap(t_list **stack, int *value)
{
    int gap;
    int i;
    int ret;

    i = 0;
    go_to_first_el(stack);
    ret = i;
    *value = *(int*)(*stack)->value;
    gap = *(int*)(*stack)->value - *(int*)(*stack)->next->value;
    while ((*stack)->next)
    {
        if (*(int*)(*stack)->value - *(int*)(*stack)->next->value > gap)
        {
            ret = i;
            *value = *(int*)(*stack)->value;
            gap = *(int*)(*stack)->value - *(int*)(*stack)->next->value;
        }
        (*stack) = (*stack)->next;
        i++;
    }
    return (ret);
}

void    last_sort(t_list **stack_b, t_count *count, t_list **cmd)
{
    go_to_first_el(stack_b);
    count->stack_b_idx = index_max_el(stack_b, find_min(*stack_b)) + 1;
    if (count->stack_b_idx <= count->stack_b_nb / 2)
    {
        while (count->stack_b_idx > 0)
        {
            ft_rb(*stack_b, cmd);
            go_to_first_el(stack_b);
            count->stack_b_idx--;
        }
    }
    else
    {
        while (count->stack_b_idx < count->stack_b_nb)
        {
            ft_rrb(*stack_b, cmd);
            go_to_first_el(stack_b);
            count->stack_b_idx++;
        }
    }
}

void    high_limit(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd)
{
    if (count->stack_b_idx > count->stack_b_nb / 2)
    {
        while (count->stack_b_idx < count->stack_b_nb && count->r_or_rr == 1 && count->stack_a_idx)
        {
            ft_rrr(*stack_a, *stack_b, cmd);
            count->stack_b_idx++;
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 1 && count->stack_a_idx)
        {
            ft_rra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 0 && count->stack_a_idx)
        {
            ft_ra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->stack_b_idx < count->stack_b_nb)
        {
            ft_rrb(*stack_b, cmd);
            go_to_first_el(stack_b);
            count->stack_b_idx++;
        }
    }
}

void    low_limit(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd)
{
    if (count->stack_b_idx <= count->stack_b_nb / 2)
    {
        while (count->stack_b_idx > 0 && count->r_or_rr == 0 && count->stack_a_idx)
        {
            ft_rr(*stack_a, *stack_b, cmd);
            count->stack_b_idx--;
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 0 && count->stack_a_idx)
        {
            ft_ra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 1 && count->stack_a_idx)
        {
            ft_rra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->stack_b_idx > 0)
        {
            ft_rb(*stack_b, cmd);
            count->stack_b_idx--;
        }
    }
}

void    high_insert(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd)
{
    if (count->stack_b_idx > count->stack_b_nb / 2)
    {
        while (count->stack_b_idx < count->stack_b_nb - 1 && count->r_or_rr == 1 && count->stack_a_idx)
        {
            ft_rrr(*stack_a, *stack_b, cmd);
            count->stack_b_idx++;
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 1 && count->stack_a_idx)
        {
            ft_rra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 0 && count->stack_a_idx)
        {
            ft_ra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->stack_b_idx < count->stack_b_nb - 1)
        {
            ft_rrb(*stack_b, cmd);
            count->stack_b_idx++;
        }
    }
}

void    low_insert(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd)
{
    if (count->stack_b_idx <= count->stack_b_nb / 2)
    {
        while (count->stack_b_idx >= 0 && count->r_or_rr == 0 && count->stack_a_idx)
        {
            ft_rr(*stack_a, *stack_b, cmd);
            count->stack_b_idx--;
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 0 && count->stack_a_idx)
        {
            ft_ra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->r_or_rr == 1 && count->stack_a_idx)
        {
            ft_rra(*stack_a, cmd);
            count->stack_a_idx--;
        }
        while (count->stack_b_idx >= 0)
        {
            ft_rb(*stack_b, cmd);
            count->stack_b_idx--;
        }
    }
}

void    set_index_limit(t_list **stack_a, t_list **stack_b, t_count *count)
{
    go_to_first_el(stack_b);
    go_to_first_el(stack_a);
    if (*(int*)(*stack_a)->value > find_max(*stack_b))
        count->stack_b_idx = index_max_el(stack_b, find_max(*stack_b));
    else
        count->stack_b_idx = index_max_el(stack_b, find_min(*stack_b)) + 1;
}

void    handle_limits(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd)
{
    set_index_limit(stack_a, stack_b, count);
    high_limit(stack_a, stack_b, count, cmd);
    low_limit(stack_a, stack_b, count, cmd);
}

void    sort(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd)
{
    count->r_or_rr = 0;
    count->stack_a_idx = 0;
    count->stack_b_idx = 0;
    if (count->stack_a_nb == 0)
    {
        last_sort(stack_b, count, cmd);
        return ;
    }
    if (*stack_b && count_el(*stack_b) > 0)
    {
        go_to_first_el(stack_a);
        choose_value(stack_a, *stack_b, count);
        if (count->stack_b_idx == -1)
            handle_limits(stack_a, stack_b, count, cmd);
        else
        {
            high_insert(stack_a, stack_b, count, cmd);
            low_insert(stack_a, stack_b, count, cmd);
        }
    }
    ft_pb(stack_a, stack_b, cmd);
    count->stack_a_nb--;
    count->stack_b_nb++;
    sort(stack_a, stack_b, count, cmd);
}

void    push_swap(t_list **stack_a, t_list **stack_b, int nb, t_list **cmd)
{
    int x;
    int max;
    int j;
    t_count count;

    x = 0;
    j = nb;
    max = 0;
    init_struct_count(&count, nb);
//    print_no_details(*stack_a, *stack_b);
    sort(stack_a, stack_b, &count, cmd);
    if (*stack_b)
        go_to_first_el(stack_b);
    while (*stack_b)
        ft_pa(stack_a, stack_b, cmd);
//    print_no_details(*stack_a, *stack_b);
}

void    print_commands(t_list **cmd)
{
    while ((*cmd)->next)
    {
        printf("cmd %s\n", (char *)(*cmd)->value);
        *cmd = (*cmd)->next;
    }
    printf("cmd %s\n", (char *)(*cmd)->value);
}

void    print_count(t_list **cmd)
{
    int i;

    i = 0;
    go_to_first_el(cmd);
    while ((*cmd)->next)
    {
        *cmd = (*cmd)->next;
        i++;
    }
    printf("count %d\n", i);
}

int main(int ac, char **av)
{
    int i;
    t_list *stack_a;
    t_list *stack_b;
    t_list *tmp;
    t_list *cmd;
    int     *nb;

    i = 1;
    tmp = NULL;
    cmd = NULL;
    nb = malloc(sizeof(int));
    *nb = ft_atoi(av[i]);
    init_stacks(&stack_a, &stack_b);
    if (ac < 2)
        return (0);
    stack_a = ft_lstnew(nb);
    i++;
    while (i < ac)
    {
        nb = malloc(sizeof(int));
        *nb = ft_atoi(av[i]);
        ft_lst_addback(&stack_a, ft_lstnew(nb));
        i++;
    }
//    print_no_details(stack_a, stack_b);
//    printf("\n");
    push_swap(&stack_a, &stack_b, ac - 1, &cmd);
    if (checker_min(stack_a))
        printf("OK");
    print_no_details(stack_a, stack_b);
//   printf("cmd value %s\n", (char *)cmd->value);
    go_to_first_el(&cmd);
//    print_commands(&cmd);
    print_count(&cmd);
    free_stack(stack_a);
    free_stack(cmd);
    free_stack(stack_b);
    return (0);
}