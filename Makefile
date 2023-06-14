NAME = philo
NAME2 = philo
SRCS =	code/main.c code/philo_utils.c code/printf_functions.c code/monitor.c

OBJS	= $(SRCS:.c=.o)
CC = cc
RM = rm -f
FLAGS = -g -pthread -Wall -Werror -Wextra

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: cool_script ${NAME}
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
${NAME}: ${OBJS}
		${CC} ${FLAGS} -o $(NAME2) $(OBJS)

cool_script:
	clear
	for i in 1 2 3 ; do \
        echo "$(YELLOW)🧙Welcome to Philosophers🧙$(DEF_COLOR)" \
       	&& sleep 0.4 \
        && clear \
        && echo "$(GREEN)🧙Welcome to Philosophers🧙$(DEF_COLOR)" \
       	&& sleep 0.4 \
        && clear ; done
	echo "READY"
	sleep 0.3
	echo "-"
	sleep 0.2
	echo "--"
	sleep 0.2
	echo "---"
	sleep 0.5
	clear
	echo "ᕙ( ︡’︡ 益 ’︠)ง▬▬█"
	sleep 1.05
	clear

clean:
	${RM} ${OBJS}
	@echo ok

fclean: clean
	$(RM) ${NAME2}
	@echo rm -f ./philo code/main.o code/monitor.o code/philo_utils.o code/printf_functions.o

re: fclean all

.PHONY: all clean fclean re
.SILENT:
