/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** display_syscalls.c
*/

#include "strace.h"

long long int	neg_to_pos_number(long long int nb)
{
	if (nb < 0)
		return (++nb);
	return (nb);
}

int		conv_decimal(t_strace *st, long long int id)
{
	st->retval = (int)id;
	return (st->retval);
}

int		display_only_regs(t_strace *st)
{
	if (st->sys->nb_params > 0) {
		printf("0x%llx", st->reg.rdi);
		if (st->sys->id == 231)
			st->retval = conv_decimal(st, st->reg.rdi);
	}
	if (st->sys->nb_params > 1)
		printf(", 0x%llx", st->reg.rsi);
	if (st->sys->nb_params > 2)
		printf(", 0x%llx", st->reg.rdx);
	if (st->sys->nb_params > 3)
		printf(", 0x%llx", st->reg.r8);
	if (st->sys->nb_params > 4)
		printf(", 0x%llx", st->reg.r10);
	if (st->sys->nb_params > 5)
		printf(", 0x%llx", st->reg.r9);
	return (0);
}

int		display_return_type(t_strace *st)
{
	long	long	int	new_nb = 0;

	if (st->sys->return_type == 0)
		printf(") = ?\n");
	else {
		if ((ptrace(PTRACE_SINGLESTEP, st->pid, 0, 0)) == -1)
			return (my_error("SINGLESTEP failed\n"));
		waitpid(st->pid, &st->wstatus, 0);
		if ((ptrace(PTRACE_GETREGS, st->pid, 0, &st->reg)) == -1)
			return (my_error("GETREGS failed\n"));
		new_nb = neg_to_pos_number(st->reg.rax);
		printf(") = 0x%llx\n", new_nb);
	}
	return (0);
}

int		display_syscall(t_strace *st)
{
	st->sys = get_id_syscall(st->reg.rax);
	if (st->sys == NULL)
		return (1);
	printf("Syscall %s(", st->sys->name);
	display_only_regs(st);
	display_return_type(st);
	return (0);
}
