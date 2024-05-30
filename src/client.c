/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:44:54 by bschneid          #+#    #+#             */
/*   Updated: 2024/05/30 15:56:13 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// global variable (message) to print letterwise while receiving acknoledgement
char	*g_string;

// change (increase) usleep to optimize "clean" sending in different systems
static void	encode(int pid, char *str)
{
	char	i;
	char	letter;

	ft_printf("\nSending message...\n\n");
	while (*str)
	{
		i = 8;
		while (i--)
		{
			letter = *str >> i;
			if (letter & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
		str++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

// signal handler for receiveded signals: SIGUSR1 and SIGUSR2
static void	received(int sig, siginfo_t *info, void *ucontext)
{
	static pid_t	pid = 0;

	(void) ucontext;
	if (!pid)
		pid = info->si_pid;
	else if (pid != info->si_pid)
		return ;
	if (sig == SIGUSR1 && *g_string)
	{
		write(1, g_string, 1);
		usleep(200);
		g_string++;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("\n\t--- Server (PID %i) end was received! ---\n\n", pid);
		pid = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;

	if (argc != 3 || !ft_isai(argv[1]) || ft_atoi(argv[1]) < 0)
	{
		ft_printf("\t### Input-Error ###\n\tExecutable must ");
		ft_printf("be followed by PID and message \"...\" !\n");
	}
	else
	{
		sigemptyset(&action.sa_mask);
		sigaddset(&action.sa_mask, SIGUSR1);
		sigaddset(&action.sa_mask, SIGUSR2);
		action.sa_flags = SA_RESTART | SA_SIGINFO;
		action.sa_sigaction = received;
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		g_string = argv[2];
		encode(ft_atoi(argv[1]), argv[2]);
		while (*g_string)
			;
		usleep(25000);
	}
}
