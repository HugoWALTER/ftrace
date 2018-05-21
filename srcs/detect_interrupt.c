/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** detect_interrupt.c
*/

#include "strace.h"

int	get_interrupt(t_strace *st)
{
	unsigned short	rip;

	rip = ptrace(PTRACE_PEEKTEXT, st->pid, st->reg.rip, 0);
	if (rip == 0x80CD || rip == 0x50F)
		return (1);
	if (rip == 0xFFFF) {
		my_error("PEEKTEXT failed\n");
		exit(1);
	}
	return (0);
}

int	get_fct_interrupt(t_strace *st)
{
	st->rip = ptrace(PTRACE_PEEKTEXT, st->pid, st->reg.rip, 0);
	if (IS_A_FCT(st->rip))
		return (1);
	if (st->rip == 0xFFFF) {
		my_error("PEEKTEXT failed\n");
		exit(1);
	}
	return (0);
}
