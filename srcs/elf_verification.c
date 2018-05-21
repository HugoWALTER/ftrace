/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** elf_verification.c
*/

#include "strace.h"

int	xopen(const char *pathname, int flags)
{
	int	fd = 0;

	fd =  open(pathname, flags);
	if (fd == -1) {
		perror("open");
		exit(1);
	}
	return (fd);
}

void	*xelf_begin(int fd, Elf_Cmd cmd, Elf *elf)
{
	elf = elf_begin(fd, cmd, NULL);
	if (elf == NULL) {
		perror("elf_begin");
		exit(1);
	}
	return (elf);
}

void	*xelf_getdata(Elf_Scn *scn, Elf_Data *data)
{
	data = elf_getdata(scn, NULL);
	if (data == NULL) {
		perror("elf_getdata");
		exit(1);
	}
	return (data);
}
