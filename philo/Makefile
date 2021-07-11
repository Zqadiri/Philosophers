# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 11:05:48 by zqadiri           #+#    #+#              #
#    Updated: 2021/07/10 20:40:30 by zqadiri          ###   ########.fr        #
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
		go_to_sleep.c\
		think.c\
		is_done.c\
		is_dead.c\
		philo.c

OBJS = $(SRCS:.c=.o)
all:   $(NAME)

$(NAME) : $(OBJS)
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