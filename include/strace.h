/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** strace.h
*/

#ifndef	STRACE_H
#define	STRACE_H

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "syscall.h"
#include "stgelf.h"
#include "signals.h"

#define IS_A_FCT(x) ((x & 0xFF) == 0xE8)

typedef struct	user_regs_struct	t_pt_reg;

enum	s_enum
{
	MAIN_ON,
	MAIN_OFF
};

typedef	struct	s_nm
{
	int				count;
	int				ct;
	Elf64_Shdr			*shdrs;
	char				*strs;
	Elf64_Shdr			*strtab;
	Elf64_Shdr			*symtab;
	Elf64_Sym			*symbold;
	char				*tab_offset;
	long unsigned int		value;
}	t_nm;

typedef struct	s_strace
{
	pid_t				tp;
	int				launch;
	char				**cp_av;
	pid_t				pid;
	int				wstatus;
	int				retval;
	int				disp_val;
	unsigned long long int		rip;
	unsigned long long int		op;
	unsigned long long int		addr_func;
	char				*addr_str;
	char				*addr_to_scan;
	char				*name_binary;
	int				main_status;
	char				*name_fct;
	t_syscall	const		*sys;
	t_signals	const		*sgl;
	t_pt_reg			reg;
}	t_strace;

int		main(int, char **, char **);
int		my_error(char *);
int		get_av(int, char **, t_strace *);
int		error_handling(int, char **, t_strace *);
int		usage(t_strace *);
int		error_usage(t_strace *);
int		xfree(t_strace *);
int		clear_end(t_strace *);
int		fork_child_and_prt(t_strace *, char **);
int		call_prt(t_strace *);
t_syscall	const	*get_id_syscall(int);
long long int	neg_to_pos_number(long long int);
int		display_only_regs(t_strace *);
int		display_return_type(t_strace *);
int		display_syscall(t_strace *);
int		get_interrupt(t_strace *);
int		conv_decimal(t_strace *, long long int);
int		check_first_display(int, long long int);
int		check_other_display(int, long long int);
int		syscall_detection(t_strace *, int);
int		get_fct_interrupt(t_strace *);
int		nm_scanning(char *, t_strace *);
int		detection_header(void *);
int		check_file(char *);
int		detection_class(void *, t_strace *);
void		is_class32(Elf64_Ehdr *, t_strace *);
void		is_class64(Elf64_Ehdr *, t_strace *);
int		init_nm_struct(t_nm **);
t_strace	*init_other_value(t_strace *);
int		init_struct(t_strace **);
int		loading_strace(t_strace *, char **);
unsigned	long	int	get_func_addr(size_t,
					unsigned long long int, int);
void		my_swap(char *, char *);
char		*revstr(char *, unsigned int);
char		*keep_3_addr(char *);
int		find_and_store_function(t_strace *);
int		print_basic_display(t_strace *);
int		display_function(t_strace *);
int		xopen(const char *, int);
t_signals const	*get_name_sgnls(int);
int		display_sgnls(t_strace *, int *);

#endif	/* !STRACE_H */
