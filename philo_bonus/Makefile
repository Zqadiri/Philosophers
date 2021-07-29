# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 11:17:15 by zqadiri           #+#    #+#              #
#    Updated: 2021/07/27 19:30:35 by zqadiri          ###   ########.fr        #
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

NAME = philo_bonus

CC	= gcc

RM = rm -f

CMPL = 	-Wall -Werror -Wextra -fsanitize=address -g

SRCS =	print_state.c\
		get_args.c\
		philo_bonus.c

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

.PHONY: 	all fclean re clean