/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:10:36 by manykhac          #+#    #+#             */
/*   Updated: 2022/09/08 13:12:24 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-');
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10);
	ft_putchar_fd(nb % 10 + '0');
}

void	take_bits(int num)
{
	static int	i;
	static int	result;

	if (num == SIGUSR1)
		result += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(result);
		i = 0;
		result = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		write(1, "Server number is:", 17);
		ft_putnbr_fd(pid);
		ft_putchar_fd('\n');
		signal(SIGUSR1, take_bits);
		signal(SIGUSR2, take_bits);
		while (1)
			pause();
	}
	return (0);
}
