/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:06:59 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/29 18:20:23 by hectordavro      ###   ########.fr       */
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

char  **creat_argument(char **av, int ac)
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
        number_element();
        exit(0);
    }
    else
        args = creat_argument(av, ac);
    execv_puswap(args);
}