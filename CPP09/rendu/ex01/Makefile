# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 12:57:06 by rahmed            #+#    #+#              #
#    Updated: 2023/03/19 12:57:06 by rahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	RPN

SRCS			=	${SRC_DIR}/main.cpp \
					${SRC_DIR}/RPN.cpp

ARG				=	"8  9 * 9 - 9 - 9 - 4 - 1 + 2 2/-"
CALC			=	1

SRC_DIR			=	srcs
INC_DIR			=	headers
RM				=	rm -f
AR				=	ar rcs

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
#					-Wconversion #Check implicit casts
#					-Wshadow -Wno-shadow
HEADER		=	-I${INC_DIR}
LDFLAGS		=	-L${SRC_DIR}
FSFLAGS		=	-fsanitize=address

OBJS			=	${SRCS:.cpp=.o}
%.o				:	%.cpp
					@echo "${TXT_BLUE}"
					@echo "~~~~~~~ MAKE PROJECT ~~~~~~~~"
ifeq ($(CALC), 1)
					${CC} ${CFLAGS} -DCALC ${HEADER} -c $< -o $@
else
					${CC} ${CFLAGS} ${HEADER} -c $< -o $@
endif
					@echo "${FANCY_RESET}"

${NAME}			:	${OBJS}
					@echo "${TXT_YELLOW}"
					@echo "~~~~~~~ COMPILATION ~~~~~~~~~"
					@echo "${TXT_GREEN}"
# FSANITIZE :
					${CC} ${CFLAGS} ${LDFLAGS} ${FSFLAGS} ${OBJS} -o ${NAME}
# NORMAL :
#					${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -o ${NAME}
					@echo "${FANCY_RESET}"

all			:	${NAME}

clean :
				@echo "${TXT_YELLOW}"
				@echo "~~~~~~~~~~ CLEAN ~~~~~~~~~~~~"
				@echo "${TXT_RED}"
				${RM}  ${OBJS}
				@echo "$(FANCY_RESET)"

fclean		:	clean
				@echo "${TXT_YELLOW}"
				@echo "~~~~~~~~~~ FCLEAN ~~~~~~~~~~"
				@echo "${TXT_MAGENTA}"
				${RM} ${NAME}
				@echo "$(FANCY_RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re
############### PARTIE TEST ###############
test		:
				make
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~   CPP09   ~~~~~~~~~~~"
				@echo "${FANCY_RESET}"
				./${NAME} ${ARG}

testerr		:
				make
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~   CPP09 : Empty ARG  ~~~~~~~~~~~"
				@echo "${FANCY_RESET}"
				./${NAME}

testerr1		:
				make
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~~~~   CPP09 : Inexistant file   ~~~~~~~~~~~"
				@echo "${FANCY_RESET}"
				./${NAME} toto

flush		:	fclean
				@echo "${TXT_YELLOW}"
				@echo "\n~~~~~~~ Extra-CLEANING  ~~~~~~~~"
				@echo "${TXT_RED}"
				${RM} .DS_STORE
				${RM} *.out
				${RM} *.a
				${RM} ${SRC_DIR}/*.o
				${RM} -R *.dSYM
				@echo "${FANCY_RESET}"

# Set COLORS
TXT_RED		=	\033[1;31m
TXT_GREEN	=	\033[1;32m
TXT_YELLOW	=	\033[1;33m
TXT_BLUE	=	\033[1;34m
TXT_MAGENTA	=	\033[1;35m
TXT_CYAN	=	\033[1;36m
BCK_RED		=	\033[0;41m
BCK_GREEN	=	\033[0;42m
BCK_YELLOW	=	\033[0;43m
BCK_BLUE	=	\033[0;44m
BCK_MAGENTA	=	\033[0;45m
BCK_CYAN	=	\033[0;46m
FANCY_RESET	=	\033[0m
###########################################
