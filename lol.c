/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = 0;

	while (str[i])
		my_putchar(str[i++]);
	return (0);
}

int	main(void)
{
	char	*str = "issou\n";

	my_putstr(str);
	return (0);
}
