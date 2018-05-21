/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** stgelf.h
*/

#ifndef GELF_H_
#define GELF_H_

#include <libelf.h>
#include <string.h>
#include <gelf.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_gelf
{
	Elf		*elf;
	Elf_Scn		*scn;
	GElf_Shdr	shdr;
	Elf_Data	*data;
	int		fd;
	int		count;
}	t_gelf;

int		xopen(const char *, int);
void		*xelf_begin(int, Elf_Cmd, Elf *);
void		*xelf_getdata(Elf_Scn *, Elf_Data *);
char		*set_addr(char *, GElf_Sym, Elf *, GElf_Shdr);
char		*set_name(char *, GElf_Sym, Elf *, GElf_Shdr);
void		init_gelf(t_gelf *, char *);
void		xclose(t_gelf *);
void		*addr_name(char *, char *, char *);

#endif	/* !GELF_H_ */
