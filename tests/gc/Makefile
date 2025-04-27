all:
	@mkdir -p ../../build/tests/
	@cc -Wall -Wextra -Werror ./alloc_tests.c -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion -Wcast-align -Wcast-qual \
			-Wfloat-equal -Wshadow -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
			-Wundef -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -fno-common \
			-fstrict-aliasing -fstack-protector-strong -fPIC -D_FORTIFY_SOURCE=2 -g3 -O2 \
			-fsanitize=address -fsanitize=undefined -fsanitize=leak  -o ../../build/tests/a.out -lft -I../../include/
	@../../build/tests/a.out
	@echo -e -n "\033[34m==> Looking for leaks...\r\033[0m"
	@cc -Wall -Wextra -Werror ./alloc_tests.c  -g3 -o ../../build/tests/a.out -lft -I../../include/
	@echo -e "\033[35m==> Garbage collector test\033[0m\n"
	@valgrind --quiet --error-exitcode=42 --leak-check=full ../../build/tests/a.out || echo -e "\033[31m[FAIL]\033[0m"; \

.PHONY: all
