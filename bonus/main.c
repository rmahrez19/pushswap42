/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:06:59 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/07 11:08:17 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"




char **execv_puswap(char **args)
{
	int		fd[2];
	pid_t	pid;
	char	**lines;
	char	*line;
	int		i;

	if (pipe(fd) == -1)
		return (NULL);
	pid = fork();
	if (pid < 0)
		return (close(fd[0]), close(fd[1]), NULL);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve("./push_swap", args, NULL);
		ft_printf(RED "Error execve\n");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	lines = malloc(sizeof(char *) * 1000); // à adapter dynamiquement si besoin
	if (!lines)
		return (close(fd[0]), NULL);
	i = 0;
	while ((line = get_next_line(fd[0])) != NULL)
		lines[i++] = line;
	lines[i] = NULL;
	close(fd[0]);
	wait(NULL);
	return (lines);
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
	char **moves;

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
	moves = execv_puswap(args);
	stack_a = ft_pars(args);
	printf("clear" CLEAR);
	print(stack_a, moves);
    return 0;
}