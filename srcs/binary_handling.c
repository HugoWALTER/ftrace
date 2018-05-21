/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** binary_handling.c
*/

#include "strace.h"

int	check_file(char *filename)
{
	int	fd = 0;

	if (access(filename, F_OK) == -1)
		return (my_error("Error: No such file\n"));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (my_error("Error: Permission denied\n"));
	return (fd);
}

int	detection_header(void *buffer)
{
	Elf64_Ehdr	*elf;

	elf = buffer;
	if (elf->e_ident[EI_MAG0] == 0x7f && elf->e_ident[EI_MAG1] == 'E' &&
		elf->e_ident[EI_MAG2] == 'L' && elf->e_ident[EI_MAG3] == 'F')
		return (0);
	else
		return (my_error("ERROR: file not recognized !\n"));
	return (0);
}

int	nm_scanning(char *filename, t_strace *st)
{
	int		fd = check_file(filename);
	void		*buffer;
	struct	stat	s;

	if (fd == 84)
		return (84);
	if (fstat(fd, &s) == -1)
		return (my_error("Error: fstats failed\n"));
	buffer = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (buffer == MAP_FAILED)
		return (my_error("Error: mmap failed\n"));
	if (detection_header(buffer) == 84)
		return (84);
	if (detection_class(buffer, st) == 84)
		return (my_error("Error: failed to init struct\n"));
	if (close(fd) == -1)
		return (my_error("Error: can't close the file\n"));
	if (munmap(buffer, s.st_size) == -1)
		return (my_error("Error: can't unmap\n"));
	return (0);
}
