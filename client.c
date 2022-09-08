/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:07:05 by manykhac          #+#    #+#             */
/*   Updated: 2022/09/08 13:09:42 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	result;

	result = 0;
	n = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		n = n * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * n);
}

void	send_bits(char octet, int pid)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (octet / i == 1)
		{
			kill(pid, SIGUSR1);
			octet = octet % i;
		}
		else
			kill(pid, SIGUSR2);
		i = i / 2;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc > 1 && argc < 4)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
		{
			write(2, "Error:PID.", 10);
			exit (EXIT_FAILURE);
		}
		if (argc == 3)
		{
			while (argv[2][i])
				send_bits(argv[2][i++], pid);
		}
		else if (argc == 2)
		{
			write(2, "You have not written anything to send", 37);
			exit (EXIT_FAILURE);
		}
	}
	exit (EXIT_SUCCESS);
}
