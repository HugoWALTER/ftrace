/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** signals.c
*/

#include "strace.h"

t_signals const	*get_name_sgnls(int sig)
{
	int	i = 0;

	while (st_signals[i].id != -1) {
		if (st_signals[i].sgnl == sig)
			return (&st_signals[i]);
		i++;
	}
	return (NULL);
}

int	display_sgnls(t_strace *st, int *sig)
{
	st->sgl = get_name_sgnls(*sig);
	if (st->sgl == NULL)
		return (1);
	else
		printf("Received signal %s\n", st->sgl->name);
	return (0);
}
