/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:08:44 by mrollo            #+#    #+#             */
/*   Updated: 2022/03/11 16:28:15 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

static int	ft_clean_atoi(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\t')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				n;
	unsigned int	result;

	n = 1;
	result = 0;
	i = ft_clean_atoi(nptr);
	if (nptr[i] == '-')
	{
		n = n * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		if (result > 2147483647 && n == 1)
			return (-1);
		if (result > 2147483648 && n == -1)
			return (0);
		i++;
	}
	return (result * n);
}

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

void	ft_binario(char c, pid_t pid)
{
	int	temp;
	int	i;

	i = 7;
	while (i >= 0)
	{
		temp = c & 128;
		if (temp)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		c = c << 1;
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	int		len;
	int		i;
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		len = ft_strlen(argv[2]);
		while (i < len)
		{
			ft_binario(argv[2][i], pid);
			i++;
		}
	}
}
