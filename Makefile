# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 16:53:40 by jaicastr          #+#    #+#              #
#    Updated: 2025/04/08 16:59:40 by jaicastr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
CC		:=	cc
FLAGS		:=	-Wall -Wextra -Werror -Wno-unused-result -Wstrict-overflow=5 -Wdouble-promotion \
			-Wlogical-op -Wjump-misses-init -Wunsafe-loop-optimizations -Wstrict-aliasing=2 \
			-Wpedantic -Wundef -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -O3
TESTFLAGS	:=	-Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion -Wcast-align -Wcast-qual \
			-Wfloat-equal -Wshadow -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
			-Wundef -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -fno-common \
			-fstrict-aliasing -fstack-protector-strong -fPIC -D_FORTIFY_SOURCE=2 -g3 -O2 \
			-fsanitize=address -fsanitize=undefined -fsanitize=leak -L. -lft -Iinclude
AR		:=	ar rcs
OBJDIR		:=	build
DIRS		:=	vec tstr cstr alloc in is mem num out
TESTDIR		:=	tests
BONUS		:=	lst
BONUS_SRCS	:=	$(foreach dir, $(BONUS), $(wildcard $(dir)/*.c))
BONUS_OBJS	:=	$(patsubst %.c, $(OBJDIR)/%.o, $(BONUS_SRCS))

TEST_SRCS	:=	$(wildcard $(TESTDIR)/*_tests.c)
TEST_BINS	:=	$(patsubst $(TESTDIR)/%.c,$(OBJDIR)/$(TESTDIR)/%,$(TEST_SRCS))
TEST_BIN	:=	a.out

SRCS		:=	$(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJS		:=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

SEP = @echo -e "\n\033[1;34m════════════════════════════════════════════════════════════════════════════════════════════════════\033[0m\n"

full: banner all bonus
	$(SEP)
	norminette $(SRCS) $(BONUS_SRCS)
	$(SEP)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@ -Iinclude

$(NAME): $(OBJS)
	$(SEP)
	$(AR) $@ $^
	$(SEP)

install: re
	$(SEP)
	sudo cp $(NAME) /usr/local/lib
	sudo cp include/libft.h /usr/local/include/
	$(SEP)

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(SEP)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean full

t-san: $(NAME)
	@mkdir -p $(OBJDIR)/$(TESTDIR)
	@for test in $(TEST_SRCS); do \
		name=$$(basename $$test .c); \
		out=$(OBJDIR)/$(TESTDIR)/$$name; \
		echo -e "\033[34m==> Compiling $$name\033[0m"; \
		$(CC) $$test -D BIG_TEST=1 $(TESTFLAGS) -Iinclude -L. -lft -o $$out || exit 1; \
	done
	$(SEP)
	@for bin in $(OBJDIR)/$(TESTDIR)/*_tests; do \
		echo -e "\n\033[35m==> Running $$bin\033[0m\n"; \
		timeout 0.7s $$bin || echo -e "\033[31m[FAIL] $$bin\033[0m"; \
	done
	$(SEP)

t-val: $(NAME)
	@mkdir -p $(OBJDIR)/$(TESTDIR)
	@echo -e "\033[34m==> Looking for leaks...\033[0m"
	@for test in $(TEST_SRCS); do \
		name=$$(basename $$test .c); \
		out=$(OBJDIR)/$(TESTDIR)/$$name; \
		$(CC) $$test $(FLAGS) -Iinclude -L. -lft -o $$out || exit 1; \
	done
	@for bin in $(OBJDIR)/$(TESTDIR)/*_tests; do \
		valgrind --quiet --error-exitcode=42 --leak-check=full $$bin > /dev/null || echo -e "\033[31m[FAIL] $$bin\033[0m"; \
	done

t-bench:
	@mkdir -p $(OBJDIR)/tests
	$(SEP)
	g++ tests/bench.cpp -Wall -Wextra -Werror -Wpedantic \
		-Wconversion -Wsign-conversion -Wcast-align -Wcast-qual \
		-Wshadow -Wundef -Wwrite-strings -Wredundant-decls -Winline \
		-fno-common -fstrict-aliasing -fstack-protector-strong \
		-fPIC -D_FORTIFY_SOURCE=2 -g3 -O3 \
		-fsanitize=address -fsanitize=undefined -fsanitize=leak \
		-Iinclude -L. -lft -o build/tests/a.out
	$(SEP)
	@echo -e "\033[35m*===== t_string api vs std::string (C++) =====*\033[0m"
	./$(OBJDIR)/$(TESTDIR)/$(TEST_BIN)

t-printf: fclean clean
	$(SEP)
	@$(MAKE) -C tests/pt/
	$(SEP)

t-lib: fclean clean
	$(SEP)
	@$(MAKE) -C tests/st/
	$(SEP)

t-gnl: fclean clean
	$(SEP)
	@$(MAKE) -C tests/gn/
	$(SEP)

test:
	@$(MAKE) t-lib
	@$(MAKE) t-printf
	@$(MAKE) t-gnl
	@$(MAKE) t-san
	@$(MAKE) t-val
	@$(MAKE) t-bench

apitest: banner
	norminette $(SRCS) $(BONUS_SRCS)
	@$(MAKE) t-san
	@$(MAKE) t-val

banner:
	@printf "\n\033[35m"
	@printf "⠀⠀⣠⡶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀      \033[1;35mlibft project\033[0;35m\n"
	@printf "⠀⣰⣿⠃⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀      Author : jaicastr\n"
	@printf "⢸⣿⣯⠀⠀⠀⠀⠀⠀⢠⣴⣿⣿⣿⣿⣦⠀⠀⠀⠀⠀      Version: 1.0.0\n"
	@printf "⢼⣿⣿⣆⠀⢀⣀⣀⣴⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀      Flags  : a lot lmao\n"
	@printf "⢸⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀      Build  : make full | make test\n"
	@printf "⠀⢻⣿⠋⠙⢿⣿⣿⡀⠀⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀      Repo   : github.com/lvzrr/libft\n"
	@printf "⠀⢸⠿⢆⣀⣼⣿⣿⣿⣿⡏⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⡀⣨⡙⠟⣩⣙⣡⣬⣴⣤⠏⠀⠀⠀⠀⠀⠀⣀⡀\n"
	@printf "⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⣀⣤⣾⣿⣿⡇\n"
	@printf "⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣇⠀⢸⣿⣿⠿⠿⠛⠃\n"
	@printf "⠀⠀⠀⠀⢠⣿⣿⢹⣿⢹⣿⣿⣿⢰⣿⠿⠃⠀⠀⠀⠀\n"
	@printf "⠀⢀⣀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡛⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠛⠓⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠉⠀⠉⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "\033[0m"


.PHONY: all clean fclean re bonus install full test t-san t-val t-bench
MAKEFLAGS += --no-print-directory
