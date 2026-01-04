# Variables

CC= c++
CFLAGS= -Wall -Wextra -Werror
SRC= main.cpp
OBJ= $(SRC:.cpp=.o)
NAME= phonebook

# Makeflags
MAKEFLAGS += --no-print-directory

# Colors
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
RESET := \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo " 💻 ${GREEN}Building:${RESET} ${NAME}"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@echo " 🛠️ ${BLUE} Compiling:${RESET} $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g -o0
debug: re
	@echo " ⚠️  ${RED}Compilation mode:${RESET} debug"

clean:
	@echo " 🧹 ${YELLOW}Cleaning: ${RESET}project objects"
	@rm -rf $(OBJ)

fclean: clean
	@echo " 💣 ${YELLOW}Cleaning: ${RESET}everything"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
