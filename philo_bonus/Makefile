# Colors:
NC			=	\033[0m
LRED		=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

# Compile variables
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -L .
COMPILE		=	$(CC) $(FLAGS)

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	FLAGS += -pthread
# -lrt
endif

# Code variables

NAME		=	philo_bonus

SRCS		=	$(NAME).c \
				delay_bonus.c \
				died_bonus.c \
				error_bonus.c \
				ft_atoi_bonus.c \
				ft_getmillis_bonus.c \
				init_simulation_bonus.c \
				now_bonus.c \
				philo_eat_bonus.c \
				philo_sleep_bonus.c \
				philo_think_bonus.c \
				print_state_bonus.c \
				proccess_args_bonus.c \
				return_fork_bonus.c \
				set_natural_bonus.c \
				simulation_ended_bonus.c \
				start_simulation_bonus.c \
				take_fork_bonus.c

OBJS		=	${SRCS:%.c=bin/%.o}

# Makefile logic
all: $(NAME)

debug: FLAGS += -D DEBUG_ON
debug: $(NAME)

$(NAME):	$(OBJS)
	@echo "\n${TITLE}Compiling ${YELLOW}$(NAME)${NC}\c"
	@$(COMPILE) $(OBJS) -o $(NAME)
	@echo "${LGREEN} [OK]${NC}\n"

bin/%.o: %.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ $(DEBUG)
	@echo "${GREEN} [OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME)\c"
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${LGREEN} [OK]${NC}"

re: fclean all

.PHONY: all re fclean clean

used_code: $(NAME)
	nm -u $(NAME)

files: # TODO remove
	for f in $(ls *.c); do echo "$f \\"; done
