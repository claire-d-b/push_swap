/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 05:20:35 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/10 10:51:14 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_not_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (FALSE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_doublons(char *str, char **args, int x)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strcmp(str, args[i]) == 0 && i != x)
			return (ERROR);
		i++;
	}
	return (TRUE);
}

int	check_doublons_list(char *string, t_list *stack, int x)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	go_to_first_el(&stack);
	while (stack->next)
	{
		tmp = ft_itoa(*(int *)stack->value);
		if (ft_strcmp(string, tmp) == 0 && i != x)
			return (errors(tmp, 0));
		free_string(tmp);
		i++;
		stack = stack->next;
	}
	tmp = ft_itoa(*(int *)stack->value);
	if (ft_strcmp(string, tmp) == 0 && i != x)
		return (errors(tmp, 0));
	free_string(tmp);
	return (TRUE);
}

int	handle_errors(char **args)
{
	int		i;
	int		number;
	char	*string;

	i = 0;
	string = NULL;
	number = 0;
	while (args[i])
	{
		number = ft_atoi(args[i]);
		string = ft_itoa(number);
		if (ft_strcmp(string, args[i]) || is_not_numeric(args[i]) || \
		check_doublons(args[i], args, i))
		{
			free_string(string);
			return (ERROR);
		}
		free_string(string);
		i++;
	}
	return (TRUE);
}

int	list_doublons(t_list *stack)
{
	int		number;
	char	*string;
	int		i;

	i = 0;
	string = NULL;
	number = 0;
	go_to_first_el(&stack);
	while (stack->next)
	{
		number = *(int *)stack->value;
		string = ft_itoa(number);
		if (check_doublons_list(string, stack, i))
			return (errors(string, 1));
		free_string(string);
		i++;
		stack = stack->next;
	}
	number = *(int *)stack->value;
	string = ft_itoa(number);
	if (check_doublons_list(string, stack, i))
		return (errors(string, 1));
	free_string(string);
	return (TRUE);
}
