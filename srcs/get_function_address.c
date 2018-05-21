/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** get_function_address.c
*/

#include "strace.h"

unsigned long int	get_func_addr(size_t rip,
				unsigned long long int op, int i)
{
	return (rip + (int)((op >> 8)) + i);
}

void	my_swap(char *a, char *b)
{
	char	temp = *a;

	*a = *b;
	*b = temp;
}

char	*revstr(char *s, unsigned int x)
{
	if (x == strlen(s) / 2)
		return (s);
	my_swap(&s[x], &s[strlen(s) - x - 1]);
	return (revstr(s, x + 1));
}

char	*keep_3_addr(char *str)
{
	str = strncat(strdup(str), str, 3);
	str[3] = '\0';
	revstr(str, 0);
	str = strcat(strdup("0x"), str);
	return (str);
}
