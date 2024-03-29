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
FLAGS		=	-Wall -Wextra -Werror
COMPILE		=	$(CC) $(FLAGS)

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	FLAGS += -pthread
endif

# Code variables

NAME		=	philo

SRCS		=	$(NAME).c \
				delay.c \
				died.c \
				drop_all_forks.c \
				end_simulation.c \
				error.c \
				ft_atoi.c \
				getmillis.c \
				init_simulation.c \
				live.c \
				now.c \
				philo_eat.c \
				philo_sleep.c \
				philo_think.c \
				print_simulation.c \
				print_state.c \
				proccess_args.c \
				return_fork.c \
				return_forks.c \
				set_natural.c \
				simulation_ended.c \
				start_simulation.c \
				take_fork.c \
				take_forks.c

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
