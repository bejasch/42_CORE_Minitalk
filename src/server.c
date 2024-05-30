/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:00:20 by bschneid          #+#    #+#             */
/*   Updated: 2024/05/30 15:57:17 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// to be print after receiving a 0-byte from a client (end of message)
static void	end_of_message(pid_t *pid)
{
	ft_printf("\n\t--- Whole message received from client (PID ");
	ft_printf("%i) ---\n\nWaiting for message...\n\n", *pid);
	usleep(500);
	kill(*pid, SIGUSR2);
	usleep(25000);
	*pid = 0;
}

// function to decode the received message from a client -- delay is 200us
static void	decode(int sig, siginfo_t *info, void *ucontext)
{
	static char		bit = 0;
	static char		letter = 0;
	static pid_t	pid = 0;

	(void) ucontext;
	if (!pid)
		pid = info->si_pid;
	else if (pid != info->si_pid)
		return ;
	letter += (sig == SIGUSR2);
	if (bit++ < 7)
		letter <<= 1;
	else
	{
		bit = 0;
		if (letter == 0)
			return (end_of_message(&pid));
		kill(info->si_pid, SIGUSR1);
		write(1, &letter, 1);
		letter = 0;
	}
	usleep(200);
}

int	main(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	action.sa_sigaction = decode;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("\n\t\t### SERVER with Process-ID: %d ###\n", getpid());
	ft_printf("\nWaiting for message...\n\n");
	while (1)
		;
	return (0);
}
