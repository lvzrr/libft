all:
	@mkdir -p ../../build/tests/
	@echo -e -n "\033[34m==> Looking for leaks...\r\033[0m"
	@cc -Wall -Wextra -Werror ./alloc_tests.c  -o ../../build/tests/a.out -lft -I../../include/
	@echo -e "\033[35m==> Garbage collector test\033[0m\n"
	@valgrind --quiet --error-exitcode=42 --leak-check=full ../../build/tests/a.out || echo -e "\033[31m[FAIL]n\033[0m"; \

.PHONY: all
