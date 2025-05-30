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
CC			:=	cc
GC			?= 0

FLAGS		:=	-Wall -Wextra -Werror -Wno-unused-result -Wstrict-overflow=5 -Wdouble-promotion \
			-Wlogical-op -Wjump-misses-init -Wunsafe-loop-optimizations -Wstrict-aliasing=2 \
			-Wpedantic -Wundef -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -O3 -D LK_VERB=1 \
			$(if $(filter 1,$(GC)),-D USE_GC=1,-D USE_GC=0)
AR		:=	ar rcs
OBJDIR		:=	build
DIRS		:=	arena map vec tstr cstr alloc in is mem num out
BONUS		:=	lst
BONUS_SRCS	:=	$(foreach dir, $(BONUS), $(wildcard $(dir)/*.c))
BONUS_OBJS	:=	$(patsubst %.c, $(OBJDIR)/%.o, $(BONUS_SRCS))

SRCS		:=	$(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJS		:=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

SEP = @echo -e "\n\033[1;34m════════════════════════════════════════════════════════════════════════════════════════════════════\033[0m\n"

full: banner all bonus
	$(SEP)
	@norminette $(SRCS) $(BONUS_SRCS) $(wildcard include/*.h) | grep -q 'Error' || echo "norminette OK"
	$(SEP)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -e -n "\033[34m==> Compiling...\r\033[0m"
	@$(CC) $(FLAGS) -c $< -o $@ -Iinclude

$(NAME): $(OBJS)
	@$(AR) $@ $^

install: re
	@sudo cp $(NAME) /usr/local/lib
	@sudo cp include/libft.h /usr/local/include/

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $^

all: $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean full

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


.PHONY: all clean fclean re bonus install full
MAKEFLAGS += --no-print-directory
