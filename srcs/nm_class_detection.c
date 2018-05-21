/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** nm_class_detection.c
*/

#include "strace.h"

int	init_nm_struct(t_nm **val)
{
	t_nm	*lm;

	lm = malloc(sizeof(*lm));
	if (lm == NULL)
		return (84);
	lm->count = 0;
	lm->ct = 0;
	lm->shdrs = NULL;
	lm->strs = NULL;
	lm->strtab = NULL;
	lm->symtab = NULL;
	lm->symbold = NULL;
	lm->tab_offset = NULL;
	lm->value = 0;
	*val = lm;
	return (0);
}

void	is_class64(Elf64_Ehdr *elf, t_strace *st)
{
	if (elf->e_ident[EI_CLASS] == ELFCLASS64) {
		switch (elf->e_type) {
		case ET_REL:
			st->main_status = MAIN_ON;
			break;
		case ET_EXEC:
			st->main_status = MAIN_ON;
			break;
		case ET_DYN:
			st->main_status = MAIN_ON;
			break;
		}
	}
}

void	is_class32(Elf64_Ehdr *elf, t_strace *st)
{
	if (elf->e_ident[EI_CLASS] == ELFCLASS32) {
		switch (elf->e_type) {
		case ET_REL:
			st->main_status = MAIN_ON;
			break;
		case ET_EXEC:
			st->main_status = MAIN_ON;
			break;
		case ET_DYN:
			st->main_status = MAIN_ON;
			break;
		}
	}
}

int	detection_class(void *buffer, t_strace *st)
{
	t_nm		*nm;
	Elf64_Ehdr	*elf;

	if (init_nm_struct(&nm) == 84)
		return (84);
	elf = buffer;
	is_class32(elf, st);
	is_class64(elf, st);
	free(nm);
	return (0);
}
