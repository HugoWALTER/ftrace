/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** get_syscalls.c
*/

#include "strace.h"

t_syscall const	*get_id_syscall(int id)
{
	int	i = -1;

	while (st_syscall[i].id != -1) {
		if (st_syscall[i].id == id)
			return (&st_syscall[i]);
		i++;
	}
	return (NULL);
}
