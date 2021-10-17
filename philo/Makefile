# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 11:05:48 by zqadiri           #+#    #+#              #
#    Updated: 2021/10/17 11:30:20 by zqadiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq (,$(findstring xterm,${TERM}))
	YELLOW       := $(shell tput -Txterm setaf 3)
	PURPLE       := $(shell tput -Txterm setaf 5)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

NAME = philo

CC	= gcc

RM = rm -f

CMPL = 	-Wall -Werror -Wextra

SRCS =	init.c\
		launch.c\
		take_forks.c\
		start_eat.c\
		sleep_think.c\
		is_done.c\
		is_dead.c\
		philo.c

OBJS = $(SRCS:.c=.o)
all:   $(NAME)

$(NAME) : $(SRCS)
			 @gcc $(CMPL) $(SRCS) -lpthread -o $(NAME)
			 @echo "${YELLOW}Building philo ...${RESET}"

clean:		
			@$(RM) $(OBJS)
			@echo "${PURPLE}Deleting object files ...${RESET}"

fclean: 	clean
			@rm -rf $(NAME)
			@echo "${PURPLE}Clean executables ... ${RESET}"

re:			fclean all

.PHONY: 	all fclean