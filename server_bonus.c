/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:38:22 by mrollo            #+#    #+#             */
/*   Updated: 2022/03/11 16:27:50 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

static t_minitalk	g_minitalk;

void	handle_1(int signal)
{
	(void)signal;
	g_minitalk.bit--;
	g_minitalk.c = g_minitalk.c | (1 << g_minitalk.bit);
	if (g_minitalk.bit == 0)
	{
		write(1, &g_minitalk.c, 1);
		g_minitalk.c = '\0';
		g_minitalk.bit = 8;
	}
}

void	handle_0(int signal)
{
	(void)signal;
	g_minitalk.bit--;
	if (g_minitalk.bit == 0)
	{
		write(1, &g_minitalk.c, 1);
		g_minitalk.c = '\0';
		g_minitalk.bit = 8;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("%d\n", pid);
	g_minitalk.bit = 8;
	g_minitalk.c = '\0';
	signal(SIGUSR1, handle_1);
	signal(SIGUSR2, handle_0);
	while (1)
		sleep(1);
	return (0);
}
