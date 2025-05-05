/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:06:59 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/05 20:43:59 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"




void execv_puswap(char **args)
{
    pid_t pid;

    pid = fork();
    if(pid < 0)
    {
        ft_printf(RED "Error fork");
        exit(1);
    }
    else if(pid == 0)
    {
        if(execve("./push_swap", args, NULL) == -1)
        {
            ft_printf(RED "Error execve");
            exit(EXIT_FAILURE);
        }
    }
    else
        wait(NULL);
    return ;
}

char  **creat_argument(int ac, char **av)
{
    int i;
    char **args;

    i = 1;
    args = malloc(sizeof(char *) * (ac + 1));
    if(!args)
    {
        ft_printf(RED "Error alocation");
        exit(1);
    }
    args[0] = "./push_swap";
    while (i < ac)
    {
        args[i] = av[i];
        i++;
    }
    args[ac] = NULL ;
    return (args);
}


void print_tab_3(char **args)
{
	int i = 0;

	while(args[i])
	{
		printf(RESET "%s\n", args[i]);
		i++;
	}
}
int main(int ac, char **av)
{
    char **args;
	t_stack *stack_a;

    if(ft_print_loby() == 1)
    {

        ac = number_element();
		args = ft_random_element(ac);
		print_tab_3(ft_random_element(ac));
    }
    else
	{
        args = creat_argument(ac, av);
	}
	execv_puswap(args);
	stack_a = ft_pars(args);
	print(stack_a);
	// printf("%s", get_next_line(1));
    return 0;
}