/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:35:21 by manykhac          #+#    #+#             */
/*   Updated: 2022/09/08 13:35:41 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

void	ft_putchar_fd(char c);
void	ft_putnbr_fd(int nb);
void	take_bits(int num);
int		ft_atoi(const char *str);
void	send_bits(char octet, int pid);

#endif
