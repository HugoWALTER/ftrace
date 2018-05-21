/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** unit_tests.c
*/

#include <criterion/criterion.h>
#include "strace.h"

Test(return_value, print_basic_display)
{
	char	*expected_str = "issou";

	cr_assert_eq(strcmp(expected_str, "issou"), 0);
}

Test(ret_main, main_ret_0)
{
	int	ac = 0;
	char	**av = NULL;
	char	**ae  =NULL;

	cr_assert(main(ac, av, ae) == 0, "issou");

}
