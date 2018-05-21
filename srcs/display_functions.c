/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** display_functions.c
*/

#include "strace.h"

int	find_and_store_function(t_strace *st)
{
	st->name_fct = calloc(200, sizeof(char));
	if (st->name_fct == NULL)
		return (my_error("Failed to calloc display fct\n"));
	st->op = ptrace(PTRACE_PEEKTEXT, st->pid, st->reg.rip, 0);
	if ((int)st->op == -1)
		return (1);
	st->addr_func = get_func_addr(st->reg.rip, st->op, 5);
	st->addr_str = calloc(500, sizeof(char));
	if (st->addr_str == NULL)
		return (1);
	st->addr_to_scan = calloc(500, sizeof(char));
	if (st->addr_to_scan == NULL)
		return (1);
	sprintf(st->addr_str, "0x%llx", st->addr_func);
	st->addr_to_scan = revstr(st->addr_str, 0);
	st->addr_to_scan = keep_3_addr(st->addr_to_scan);
	return (0);
}

int	print_basic_display(t_strace *st)
{
	char	*tmp = calloc(500, sizeof(char));

	if (tmp == NULL)
		return (my_error("Failed to calloc basic display\n"));
	tmp = strcat(tmp, "func_");
	sprintf(tmp + strlen(tmp), "0x%llx", st->addr_func);
	tmp = strcat(tmp, "@");
	tmp = strcat(tmp, st->name_binary);
	printf("%s\n", tmp);
	return (0);
}

int	display_function(t_strace *st)
{
	find_and_store_function(st);
	if (addr_name(st->name_binary, st->addr_to_scan, "addr")) {
		st->name_fct = (char *)addr_name(st->name_binary,
		st->addr_to_scan, "addr");
		printf("Entering function %s at 0x%llx\n",
		st->name_fct, st->addr_func);
		printf("Leaving function %s\n", st->name_fct);
	} else
		print_basic_display(st);
	free(st->addr_str);
	return (0);
}
