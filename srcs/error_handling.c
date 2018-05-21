/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** error_handling.c
*/

#include "strace.h"

int	my_error(char *str)
{
	fprintf(stderr, str);
	return (84);
}

int	get_av(int ac, char **av, t_strace *st)
{
	int	i = 0;
	int	j = 0;

	st->cp_av = calloc((ac), (sizeof(char *)));
	if (st->cp_av == NULL)
		return (my_error("calloc failed\n"));
	while (av[++i] && av[i] && av[i][0] == '-');
	while (av[i])
		st->cp_av[j++] = av[i++];
	return (0);
}

int	error_handling(int ac, char **av, t_strace *st)
{
	if (ac < 2 || ac > 3)
		return (error_usage(st));
	if (ac == 2) {
		st->name_binary = av[1];
		get_av(ac, av, st);
		if (nm_scanning(st->name_binary, st) == 84)
			return (84);
	}
	return (0);
}
