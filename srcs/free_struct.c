/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** free_struct.c
*/

#include "strace.h"

int	xfree(t_strace *st)
{
	free(st);
	return (84);
}

int	clear_end(t_strace *st)
{
	free(st);
	return (0);
}
