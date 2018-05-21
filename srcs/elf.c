/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** elf.c
*/

#include "stgelf.h"

char	*set_addr(char *function, GElf_Sym sym, Elf *elf, GElf_Shdr shdr)
{
	char	*str = calloc(100, sizeof(char));
	char	*ret = calloc(100, sizeof(char));

	if ((int)sym.st_value)
		sprintf(str, "0x%llx", (long long unsigned int)sym.st_value);
	if (strcmp(function, str) == 0) {
		sprintf(ret, "%s", elf_strptr(elf, shdr.sh_link, sym.st_name));
		return (ret);
	}
	free(ret);
	free(str);
	return (NULL);
}

char	*set_name(char *function, GElf_Sym sym, Elf *elf, GElf_Shdr shdr)
{
	char	*str = calloc(100, sizeof(char));
	char	*ret = calloc(100, sizeof(char));

	if ((char *)elf_strptr(elf, shdr.sh_link, sym.st_name))
		sprintf(str, "%s",
		(char *)elf_strptr(elf, shdr.sh_link, sym.st_name));
	if (strcmp(function, str) == 0) {
		sprintf(ret, "0x%llx", (long long unsigned int)sym.st_value);
		return (ret);
	}
	free(ret);
	free(str);
	return (NULL);
}

void	init_gelf(t_gelf *gelf, char *filename)
{
	elf_version(EV_CURRENT);
	gelf->fd = xopen(filename, O_RDONLY);
	gelf->elf = xelf_begin(gelf->fd, ELF_C_READ, NULL);
	gelf->scn = NULL;
	while ((gelf->scn = elf_nextscn(gelf->elf, gelf->scn)) != NULL) {
		gelf_getshdr(gelf->scn, &(gelf->shdr));
		if (gelf->shdr.sh_type == SHT_SYMTAB) {
			break;
		}
	}
	gelf->data = xelf_getdata(gelf->scn, NULL);
	if (gelf->shdr.sh_entsize == 0)
		exit(84);
	gelf->count = gelf->shdr.sh_size / gelf->shdr.sh_entsize;
}

void	xclose(t_gelf *gelf)
{
	elf_end(gelf->elf);
	if (close(gelf->fd) == -1) {
		perror("close");
		exit(1);
	}
}

void	*addr_name(char *filename, char *function, char *flag)
{
	char		*str = calloc(100, sizeof(char));
	char		*ret = calloc(100, sizeof(char));
	t_gelf		gelf;
	GElf_Sym	sym;

	init_gelf(&gelf, filename);
	for (int i = 0 ; i < gelf.count ; ++i) {
		gelf_getsym(gelf.data, i, &sym);
		if (strcmp(flag, "addr") == 0)
			((str = set_addr(function, sym, gelf.elf, gelf.shdr))
			!= NULL) ? strcpy(ret, str) : NULL;
		if (strcmp(flag, "name") == 0)
			((str = set_name(function, sym, gelf.elf, gelf.shdr))
			!= NULL) ? strcpy(ret, str) : NULL;
	}
	xclose(&gelf);
	free(str);
	if (ret[0] == '\0')
		return (NULL);
	return ((void *)ret);
}
