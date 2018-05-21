/*
** EPITECH PROJECT, 2018
** PSU_ftrace_2017
** File description:
** signals.h
*/

#ifndef	SIGNALS_H
#define	SIGNALS_H

#include <signal.h>

typedef	struct	s_signals
{
	int	id;
	int	sgnl;
	char	*name;
}	t_signals;

static	const t_signals		st_signals[] = {
	{ 0, SIGHUP, "SIGHUP" },
	{ 1, SIGINT, "SIGINT" },
	{ 2, SIGQUIT, "SIGQUIT" },
	{ 3, SIGILL, "SIGILL" },
	{ 4, SIGTRAP, "SIGTRAP" },
	{ 5, SIGABRT, "SIGABRT" },
	{ 6, SIGIOT, "SIGIOT" },
	{ 7, SIGBUS, "SIGBUS" },
	{ 8, SIGFPE, "SIGFPE" },
	{ 9, SIGKILL, "SIGKILL" },
	{ 10, SIGUSR1, "SIGUSR1" },
	{ 11, SIGSEGV, "SIGSEGV" },
	{ 12, SIGUSR2, "SIGUSR2" },
	{ 13, SIGPIPE, "SIGPIPE" },
	{ 14, SIGALRM, "SIGALRM" },
	{ 15, SIGTERM, "SIGTERM" },
	{ 16, SIGSTKFLT, "SIGSTKFLT" },
	{ 17, SIGCHLD, "SIGCHLD" },
	{ 18, SIGCONT, "SIGCONT" },
	{ 19, SIGSTOP, "SIGSTOP" },
	{ 20, SIGTSTP, "SIGTSTP" },
	{ 21, SIGTTIN, "SIGTTIN" },
	{ 22, SIGTTOU, "SIGTTOU" },
	{ 23, SIGURG, "SIGURG" },
	{ 24, SIGXCPU, "SIGXCPU" },
	{ 25, SIGXFSZ, "SIGXFSZ" },
	{ 26, SIGVTALRM, "SIGVTALRM" },
	{ 27, SIGPROF, "SIGPROF" },
	{ 28, SIGWINCH, "SIGWINCH" },
	{ 29, SIGPOLL, "SIGPOLL" },
	{ 30, SIGPWR, "SIGPWR" },
	{ 31, SIGSYS, "SIGSYS" },
	{ -1, -1, "UNKNOWN" }
};

#endif	/* !STRACE_H */
