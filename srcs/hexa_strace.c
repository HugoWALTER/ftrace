/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** hexa_strace.c
*/

#include "strace.h"

int	syscall_detection(t_strace *st, int i)
{
	int	k = 0;

	if ((ptrace(PTRACE_GETREGS, st->pid, 0, &st->reg)) == -1)
		return (my_error("GETREGS parent failed\n"));
	k = get_fct_interrupt(st);
	i = get_interrupt(st);
	if ((ptrace(PTRACE_SINGLESTEP, st->pid, 0, 0)) == -1)
		return (my_error("SINGLESTEP parent failed\n"));
	waitpid(st->pid, &st->wstatus, 0);
	display_sgnls(st, &st->wstatus);
	if (k != 0)
		if (display_function(st) == 1)
			return (my_error("PEEKTEXT failed in show func\n"));
	if (i != 0)
		if (display_syscall(st) == 1)
			return (my_error("Failed to find sys id\n"));
	return (0);
}

int	call_prt(t_strace *st)
{
	int	i = 0;

	waitpid(st->pid, &st->wstatus, 0);
	if (st->main_status == MAIN_ON) {
		if ((char *)addr_name(st->name_binary, "main", "name") == NULL)
			st->main_status = MAIN_OFF;
		else
			printf("Entering function main at %s\n",
			(char *)addr_name(st->name_binary, "main", "name"));
	}
	while ((!WIFEXITED(st->wstatus)))
		syscall_detection(st, i);
	if (st->main_status == MAIN_ON)
		printf("Leaving function main\n");
	return (0);
}

int	fork_child_and_prt(t_strace *st, char **ae)
{
	pid_t	pid = fork();

	if (pid == -1)
		return (my_error("pid failed\n"));
	st->pid = pid;
	if (st->pid == 0) {
		if ((ptrace(PTRACE_TRACEME, 0, 0, 0)) == -1)
			return (my_error("TRACEME child failed\n"));
		kill(getpid(), SIGSTOP);
		return (execve(st->cp_av[0], st->cp_av, ae));
	}
	else
		return (call_prt(st));
	return (0);
}
