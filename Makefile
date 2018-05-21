##
## EPITECH PROJECT, 2018
## PSU_ftrace_2017
## File description:
## Makefile
##

NAME	=	ftrace

NAME2	=	tests_strace

SRC	=	srcs/strace.c			\
		srcs/get_syscall.c		\
		srcs/detect_interrupt.c		\
		srcs/display_syscalls.c		\
		srcs/error_handling.c		\
		srcs/usage.c			\
		srcs/free_struct.c		\
		srcs/hexa_strace.c		\
		srcs/elf.c			\
		srcs/binary_handling.c		\
		srcs/nm_class_detection.c	\
		srcs/signals.c			\
		srcs/get_function_address.c	\
		srcs/display_functions.c	\
		srcs/elf_verification.c

SRC2	=	tests/unit_tests.c

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

CC	=	gcc

CFLAGS	=	-I./include -W -Werror -Wall -Wextra

LDFLAGS	=	-lelf -lcriterion

RM	=	rm -rf

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(NAME2):	$(OBJ2)
		$(CC) $(OBJ2) -o $(NAME2) $(LDFLAGS) -coverage

tests_run:	$(NAME2)
		./$(NAME2)

clean:
		$(RM) $(OBJ) srcs/*.gc*

fclean: 	clean
		$(RM) $(NAME) $(NAME2)

re:     	fclean all
