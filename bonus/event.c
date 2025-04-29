/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:00:13 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/29 12:00:37 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char getch(void)
{
    struct termios oldt;
    struct termios newt;
    char ch;

    if (tcgetattr(STDIN_FILENO, &oldt) < 0)
        return -1;
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) < 0)
        return -1;
    if (read(STDIN_FILENO, &ch, 1) < 0)
        return -1;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldt) < 0)
        return -1;
    return ch;
}