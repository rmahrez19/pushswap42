/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:06:59 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/03 18:11:19 by ramahrez         ###   ########.fr       */
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
int main(int ac, char **av)
{
    char **args;

    if(ft_print_loby() == 1)
    {
        ac = number_element();
		args = creat_argument(ac, ft_random_element(ac));
    }
    else
        args = creat_argument(ac, av);
    execv_puswap(args);
}