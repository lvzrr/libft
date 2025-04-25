/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:50:30 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/24 10:52:51 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tstr.h"
#include "cstr.h"
#include "limits.h"
#include "printf.h"

#ifndef BIG_TEST
#define BIG_TEST 0
#endif
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define PURPLE "\033[0;35m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define UNDER   "\033[4m"
#define BLINK   "\033[5m"
#define REVERSE "\033[7m"
#define HIDDEN  "\033[8m"

void tstr_new(void);
void tstr_push_test(void);
void tstr_pushstr_test(void);
void tstr_borrow_test(void);
void tstr_from_cstr_test(void);
void tstr_from_cstr_clear(void);
void tstr_fit(void);
void tstr_instr(void);
void tstr_trim(void);
void tstr_reserve(void);
void tstr_pop(void);
void tstr_repeat(void);
void tstr_insert(void);

void tstr_new(void)
{
	t_string test;

	test = ft_tstr_new(12);
	if (test.alloc_size != 13 || test.len != 0)
		ft_printf("\nFAILED: ft_tstr_new(12)\n");
	else
		ft_printf("\033[0;32m1.OK\033[0m ");
	ft_tstr_free(&test);
	test = ft_tstr_new(-12);
	if (test.alloc_size != 0 || test.len != 0 || test.data != NULL)
		ft_printf("\nFAILED: ft_tstr_new(-12)\n");
	else
		ft_printf("\033[0;32m2.OK\033[0m ");
	ft_tstr_free(&test);
	if (BIG_TEST)
	{
		test = ft_tstr_new(INT_MAX);
		if (test.alloc_size != (size_t)INT_MAX + 1 || test.len != 0)
			ft_printf("\nFAILED: ft_tstr_new(INT_MAX)\n");
		else
			ft_printf("\033[0;32m3.OK\033[0m ");
		ft_tstr_free(&test);
	}
	test = ft_tstr_new(0);
	if (test.alloc_size != 1 || test.len != 0 || test.data[0] != '\0')
		ft_printf("\nFAILED: ft_tstr_new(0)\n");
	else
		ft_printf("\033[0;32m4.OK\033[0m ");
	ft_tstr_free(&test);
	test = ft_tstr_new(4095);
	if (!test.data || test.data[4095] != 0)
		ft_printf("\nFAILED: ft_tstr_new(4095) not null-terminated\n");
	else
		ft_printf("\033[0;32m5.OK\033[0m ");
	ft_tstr_free(&test);
	ft_printf("\n");
}

void tstr_push_test(void)
{
	t_string str = ft_tstr_new(0);

	ft_tstr_push(&str, 'H');
	ft_tstr_push(&str, 'i');
	ft_tstr_push(&str, '!');
	if (ft_strcmp(str.data, "Hi!") != 0)
		ft_printf("\nFAILED: ft_tstr_push sequence -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m1.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_push(&str, 'H');
	ft_tstr_push(&str, 'i');
	if (ft_strcmp(str.data, "Hi") != 0)
		ft_printf("\nFAILED: ft_tstr_push prealloc -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m2.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_push(NULL, 'X');
	ft_printf("\033[0;32m3.OK\033[0m ");

	ft_tstr_push(&str, '\0');
	if (str.len != 1 || str.data[0] != '\0')
		ft_printf("\nFAILED: push '\\0' -> len: %d\n", (int)str.len);
	else
		ft_printf("\033[0;32m4.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_push(&str, (char)0xC3);
	if (str.data[0] != (char)0xC3)
		ft_printf("\nFAILED: push 0xC3 -> got: %d\n", str.data[0]);
	else
		ft_printf("\033[0;32m5.OK\033[0m ");
	ft_tstr_free(&str);
	str = ft_tstr_new(1024);
	if (str.data[1024] != '\0')
		ft_printf("\nFAILED: ft_tstr_new(1024) -> not null-terminated\n");
	else
		ft_printf("\033[0;32m6.OK\033[0m ");
	ft_tstr_free(&str);

	str = ft_tstr_new(1);
	for (int i = 0; i < 1000; i++)
		ft_tstr_push(&str, 'x');
	if (str.len != 1000 || str.data[999] != 'x')
		ft_printf("\nFAILED: ft_tstr_push x1000 -> len: %d\n", (int)str.len);
	else
		ft_printf("\033[0;32m7.OK\033[0m ");
	ft_tstr_free(&str);
	ft_printf("\n");
}

void tstr_pushstr_test(void)
{
	t_string str;

	str = ft_tstr_new(0);
	ft_tstr_pushstr(&str, "Hi!");
	if (ft_strcmp(str.data, "Hi!") != 0)
		ft_printf("\nFAILED: pushstr basic -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m1.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, "");
	if (str.len != 0 || str.data[0] != '\0')
		ft_printf("\nFAILED: pushstr empty -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m2.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, "Hello");
	ft_tstr_pushstr(&str, "World");
	if (ft_strcmp(str.data, "HelloWorld") != 0)
		ft_printf("\nFAILED: pushstr concat -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m3.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, NULL);
	if (ft_strcmp(str.data, "") != 0)
		ft_printf("\nFAILED: pushstr NULL -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m4.OK\033[0m ");
	ft_tstr_free(&str);

	str = ft_tstr_new(2);
	const char *long_str = "this is a very long string that should trigger a reallocation";
	ft_tstr_pushstr(&str, long_str);
	if (ft_strcmp(str.data, long_str) != 0)
		ft_printf("\nFAILED: pushstr long -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m5.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_pushstr(NULL, "should not crash");
	ft_printf("\033[0;32m6.OK\033[0m ");

	ft_tstr_pushstr(&str, "some");
	ft_tstr_pushstr(&str, " thing");
	if (ft_strcmp(str.data, "some thing") != 0)
		ft_printf("\nFAILED: pushstr reserved space -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m7.OK\033[0m ");
	ft_tstr_clear(&str);
	
	ft_tstr_pushstr(&str, "123");
	ft_tstr_clear(&str);
	ft_tstr_pushstr(&str, "abc");
	if (ft_strcmp(str.data, "abc") != 0)
		ft_printf("\nFAILED: reuse after clear -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m8.OK\033[0m ");
	ft_tstr_free(&str);

	str = ft_tstr_from_cstr("12345");
	if (ft_strlen(str.data) != str.len)
		ft_printf("\nFAILED: len mismatch -> ft_strlen: %u, str.len: %u\n", ft_strlen(str.data), str.len);
	else
		ft_printf("\033[0;32m9.OK\033[0m ");
	ft_tstr_clear(&str);

	str.len = 3;
	str.data[0] = 'x';
	str.data[1] = 'y';
	str.data[2] = 'z';
	str.data[3] = 0;
	ft_tstr_push(&str, '!');
	if (ft_strcmp(str.data, "xyz!") != 0)
		ft_printf("\nFAILED: realloc at boundary -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m10.OK\033[0m ");
	ft_tstr_free(&str);

	str = ft_tstr_new(0);
	const char *b = ft_tstr_borrow(&str);
	if (!b || b[0] != '\0')
		ft_printf("\nFAILED: borrow from empty -> got: \"%s\"\n", b);
	else
		ft_printf("\033[0;32m11.OK\033[0m ");
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, "ab");
	ft_tstr_pushstr(&str, "cd");
	ft_tstr_pushstr(&str, "ef");
	if (ft_strcmp(str.data, "abcdef") != 0)
		ft_printf("\nFAILED: pushstr multiple appends -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m12.OK\033[0m ");
	ft_tstr_free(&str);

	ft_tstr_pushstr(NULL, NULL);
	ft_printf("\033[0;32m13.OK\033[0m \n");
}

void tstr_borrow_test(void)
{
	t_string str = ft_tstr_new(4);
	const char *b;
	ft_tstr_push(&str, 'a');
	ft_tstr_push(&str, 'b');
	ft_tstr_push(&str, 'c');
	ft_tstr_push(&str, 'd');
	b = ft_tstr_borrow(&str);
	if (!(b && ft_strcmp(b, "abcd") == 0))
		ft_printf("\nFAILED: borrow failed -> got: \"%s\"\n", str.data);
	else
		ft_printf("\033[0;32m1.OK\033[0m ");
	ft_tstr_free(&str);
	ft_printf("\n");
}

void	tstr_from_cstr_test(void)
{
	t_string	test;

	test = ft_tstr_from_cstr("HELLO!");
	if (!test.data || ft_strcmp(test.data, "HELLO!") != 0)
		ft_printf("\nFAILED: ft_tstr_from_cstr(\"HELLO!\") -> got: \"%s\"\n", test.data);
	else
		ft_printf("\033[0;32m1.OK\033[0m ");
	ft_tstr_free(&test);

	test = ft_tstr_from_cstr(NULL);
	if (!test.data || ft_strcmp(test.data, "") != 0 || test.len != 0)
		ft_printf("\nFAILED: ft_tstr_from_cstr(NULL) -> got: \"%s\"\n", test.data);
	else
		ft_printf("\033[0;32m2.OK\033[0m ");
	ft_tstr_free(&test);

	test = ft_tstr_from_cstr("");
	if (test.data[0] != '\0')
		ft_printf("\nFAILED: ft_tstr_from_cstr(\"\") -> not null-terminated\n");
	else
		ft_printf("\033[0;32m3.OK\033[0m ");
	ft_tstr_free(&test);

	ft_printf("\n");
}

void	tstr_from_cstr_clear(void)
{
	t_string	test;

	test = ft_tstr_from_cstr("HELLO");
	ft_tstr_clear(&test);
	if (test.len != 0 || *test.data)
		ft_printf("\nFAILED: ft_tstr_clear(HELLO) -> got: \"%s\"\n", test.data);
	else
		ft_printf("\033[0;32m1.OK\033[0m ");
	ft_tstr_free(&test);

	test = ft_tstr_from_cstr("");
	ft_tstr_clear(&test);
	if (test.len != 0 || *test.data)
		ft_printf("\nFAILED: ft_tstr_clear(\"\") -> got: \"%s\"\n", test.data);
	else
		ft_printf("\033[0;32m2.OK\033[0m ");
	ft_tstr_free(&test);

	test = ft_tstr_from_cstr("HELLO");
	ft_tstr_clear(&test);
	ft_tstr_pushstr(&test, "WORLD");
	if (ft_strcmp(test.data, "WORLD") != 0 || test.len != 5)
		ft_printf("\nFAILED: ft_tstr_clear() + ft_tstr_pushstr -> got: \"%s\" | expected: WORLD\n", test.data);
	else
		ft_printf("\033[0;32m3.OK\033[0m ");
	ft_tstr_free(&test);
	ft_printf("\033[0;32m4.OK\033[0m\n");
	ft_tstr_clear(NULL);
}


void	tstr_fit(void)
{
	t_string	str;

	str = ft_tstr_from_cstr("HELLO");
	ft_tstr_fit(&str);
	if (str.len != 5 || str.alloc_size != 6)
		ft_printf(RED "\nFAILED: fit HELLO -> len: %u alloc: %u\n" RESET,
			(unsigned)str.len, (unsigned)str.alloc_size);
	else
		ft_printf(GREEN "1.OK " RESET);
	ft_tstr_free(&str);

	str = ft_tstr_new(100);
	ft_tstr_clear(&str);
	ft_tstr_fit(&str);
	if (str.len != 0 || str.alloc_size != 1)
		ft_printf(RED "\nFAILED: fit empty -> len: %u alloc: %u\n" RESET,
			(unsigned)str.len, (unsigned)str.alloc_size);
	else
		ft_printf(GREEN "2.OK " RESET);
	ft_tstr_free(&str);

	str = ft_tstr_new(5);
	ft_tstr_pushstr(&str, "hey!");
	ft_tstr_fit(&str);
	size_t expected = str.len + 1;
	if (str.alloc_size != expected)
		ft_printf(RED "\nFAILED: fit already perfect -> alloc: %u (expected %u)\n" RESET,
			(unsigned)str.alloc_size, (unsigned)expected);
	else
		ft_printf(GREEN "3.OK " RESET);
	ft_tstr_free(&str);

	str = ft_tstr_new(2);
	ft_tstr_pushstr(&str, "a very long string that should expand the buffer");
	size_t pushed_len = str.len;
	ft_tstr_fit(&str);
	if (str.alloc_size != pushed_len + 1)
		ft_printf(RED "\nFAILED: fit after pushstr -> alloc: %u len: %u\n" RESET,
			(unsigned)str.alloc_size, (unsigned)str.len);
	else
		ft_printf(GREEN "4.OK " RESET);
	ft_tstr_free(&str);

	str = ft_tstr_new(400);
	ft_tstr_pushstr(&str, "a very short string that should reduce the buffer");
	pushed_len = str.len;
	ft_tstr_fit(&str);
	if (str.alloc_size != pushed_len + 1)
		ft_printf(RED "\nFAILED: fit after pushstr -> alloc: %u len: %u\n" RESET,
			(unsigned)str.alloc_size, (unsigned)str.len);
	else
		ft_printf(GREEN "5.OK " RESET);
	ft_tstr_free(&str);

	ft_tstr_fit(NULL);
	ft_printf(GREEN "6.OK" RESET "\n");
}

void	tstr_instr(void)
{
	t_string	test;

	test = ft_tstr_new(16);
	ft_tstr_pushstr(&test, "hello");
	if (ft_tstr_instr(&test, "llo") != 2)
		ft_printf(RED "\nFAILED: instr(\"hello\", \"llo\") -> expected 2, got %d\n" RESET,
			(int)ft_tstr_instr(&test, "llo"));
	else
		ft_printf(GREEN "1.OK " RESET);
	ft_tstr_clear(&test);

	ft_tstr_pushstr(&test, "aabbcc");
	if (ft_tstr_instr(&test, "bb") != 2)
		ft_printf(RED "\nFAILED: instr(\"aabbcc\", \"bb\") -> expected 2, got %d\n" RESET,
			(int)ft_tstr_instr(&test, "bb"));
	else
		ft_printf(GREEN "2.OK " RESET);
	ft_tstr_clear(&test);

	ft_tstr_pushstr(&test, "aabbcc");
	if (ft_tstr_instr(&test, "dd") != -1)
		ft_printf(RED "\nFAILED: instr(\"aabbcc\", \"dd\") -> expected -1, got %d\n" RESET,
			(int)ft_tstr_instr(&test, "dd"));
	else
		ft_printf(GREEN "3.OK " RESET);
	ft_tstr_clear(&test);

	ft_tstr_pushstr(&test, "");
	if (ft_tstr_instr(&test, "") != 0)
		ft_printf(RED "\nFAILED: instr(\"\", \"\") -> expected 0, got %d\n" RESET,
			(int)ft_tstr_instr(&test, ""));
	else
		ft_printf(GREEN "4.OK " RESET);
	ft_tstr_clear(&test);

	ft_tstr_pushstr(&test, "abc");
	if (ft_tstr_instr(&test, "") != 0)
		ft_printf(RED "\nFAILED: instr(\"abc\", \"\") -> expected 0, got %d\n" RESET,
			(int)ft_tstr_instr(&test, ""));
	else
		ft_printf(GREEN "5.OK " RESET);
	ft_tstr_clear(&test);

	ft_tstr_pushstr(&test, "abc");
	if (ft_tstr_instr(&test, NULL) != -1)
		ft_printf(RED "\nFAILED: instr(\"abc\", NULL) -> expected -1, got %d\n" RESET,
			(int)ft_tstr_instr(&test, NULL));
	else
		ft_printf(GREEN "6.OK " RESET);
	ft_tstr_clear(&test);

	ft_tstr_instr(NULL, "abc");
	ft_tstr_instr(NULL, NULL);
	ft_printf(GREEN "7.OK 8.OK" RESET "\n");
	ft_tstr_free(&test);
}

void	tstr_trim(void)
{
	t_string s;

	s = ft_tstr_from_cstr("   hello   ");
	ft_tstr_trim(&s, " ");
	if (ft_strcmp(s.data, "hello") != 0)
		ft_printf(RED "\nFAILED: trim(\"   hello   \", \" \") -> got: \"%s\"\n" RESET, s.data);
	else
		ft_printf(GREEN "1.OK " RESET);
	ft_tstr_free(&s);

	s = ft_tstr_from_cstr("xyxyHelloxyx");
	ft_tstr_trim(&s, "xy");
	if (ft_strcmp(s.data, "Hello") != 0)
		ft_printf(RED "\nFAILED: trim(\"xyxyHelloxyx\", \"xy\") -> got: \"%s\"\n" RESET, s.data);
	else
		ft_printf(GREEN "2.OK " RESET);
	ft_tstr_free(&s);

	s = ft_tstr_from_cstr("xxx");
	ft_tstr_trim(&s, "x");
	if (ft_strcmp(s.data, "") != 0)
		ft_printf(RED "\nFAILED: trim(\"xxx\", \"x\") -> expected \"\", got: \"%s\"\n" RESET, s.data);
	else
		ft_printf(GREEN "3.OK " RESET);
	ft_tstr_free(&s);

	s = ft_tstr_from_cstr("   ");
	ft_tstr_trim(&s, " ");
	if (ft_strcmp(s.data, "") != 0)
		ft_printf(RED "\nFAILED: trim(\"   \", \" \") -> expected \"\", got: \"%s\"\n" RESET, s.data);
	else
		ft_printf(GREEN "4.OK " RESET);
	ft_tstr_free(&s);

	s = ft_tstr_from_cstr("nothing to trim");
	ft_tstr_trim(&s, "-");
	if (ft_strcmp(s.data, "nothing to trim") != 0)
		ft_printf(RED "\nFAILED: trim(\"nothing to trim\", \"-\") -> got: \"%s\"\n" RESET, s.data);
	else
		ft_printf(GREEN "5.OK " RESET);
	ft_tstr_free(&s);

	s = ft_tstr_from_cstr("");
	ft_tstr_trim(&s, " ");
	if (ft_strcmp(s.data, "") != 0)
		ft_printf(RED "\nFAILED: trim(\"\", \" \") -> got: \"%s\"\n" RESET, s.data);
	else
		ft_printf(GREEN "6.OK " RESET);
	ft_tstr_free(&s);

	ft_tstr_trim(NULL, "x");
	ft_tstr_trim(NULL, NULL);
	ft_printf(GREEN "7.OK 8.OK" RESET "\n");
}

void tstr_reserve(void)
{
	t_string str;

	str = ft_tstr_new(0);
	ft_tstr_reserve(&str, 100);
	if (str.alloc_size < 100)
		ft_printf(RED "\nFAILED: reserve(0, 100) -> alloc: %u\n" RESET, str.alloc_size);
	else
		ft_printf(GREEN "1.OK " RESET);
	ft_tstr_free(&str);

	str = ft_tstr_new(5);
	ft_tstr_pushstr(&str, "abc");
	ft_tstr_reserve(&str, 50);
	if (str.alloc_size < str.len + 50 || ft_strcmp(str.data, "abc") != 0)
		ft_printf(RED "\nFAILED: reserve existing with content -> alloc: %u, str: %s\n" RESET,
			str.alloc_size, str.data);
	else
		ft_printf(GREEN "2.OK " RESET);
	ft_tstr_free(&str);

	str = ft_tstr_new(10);
	ft_tstr_reserve(&str, 0);
	if (str.alloc_size != 11)
		ft_printf(RED "\nFAILED: reserve(0) -> alloc: %u\n" RESET, str.alloc_size);
	else
		ft_printf(GREEN "3.OK " RESET);
	ft_tstr_free(&str);

	str = ft_tstr_new(20);
	ft_tstr_reserve(&str, 10);
	if (str.alloc_size != 21)
		ft_printf(RED "\nFAILED: reserve less than current -> alloc: %u\n" RESET, str.alloc_size);
	else
		ft_printf(GREEN "4.OK " RESET);
	ft_tstr_free(&str);

	ft_tstr_reserve(NULL, 100);
	ft_printf(GREEN "5.OK" RESET "\n");
}

void	tstr_pop(void)
{
	t_string str;
	char c;

	str = ft_tstr_from_cstr("Hello!");
	c = ft_tstr_pop(&str);
	if (c != '!' || ft_strcmp(str.data, "Hello") != 0 || str.len != 5)
		ft_printf(RED "\nFAILED: pop from \"Hello!\" -> got: '%c', str: \"%s\", len: %u\n" RESET, c, str.data, (unsigned)str.len);
	else
		ft_printf(GREEN "1.OK " RESET);

	c = ft_tstr_pop(&str);
	ft_tstr_pop(&str);
	ft_tstr_pop(&str);
	ft_tstr_pop(&str);
	c = ft_tstr_pop(&str);
	if (c != 'H' || str.len != 0 || ft_strcmp(str.data, "") != 0)
		ft_printf(RED "\nFAILED: pop to empty -> got: '%c', str: \"%s\", len: %u\n" RESET, c, str.data, (unsigned)str.len);
	else
		ft_printf(GREEN "2.OK " RESET);

	c = ft_tstr_pop(&str);
	if (c != 0)
		ft_printf(RED "\nFAILED: pop from empty -> expected '\\0', got: '%c'\n" RESET, c);
	else
		ft_printf(GREEN "3.OK " RESET);

	c = ft_tstr_pop(NULL);
	if (c != 0)
		ft_printf(RED "\nFAILED: pop from NULL -> expected '\\0', got: '%c'\n" RESET, c);
	else
		ft_printf(GREEN "4.OK " RESET);
	if (str.alloc_size != 7)
		ft_printf(RED "\nFAILED: Alloc modified -> expected 7, got: '%u'\n" RESET, str.alloc_size);
	else
		ft_printf(GREEN "5.OK" RESET);
	ft_tstr_free(&str);
	ft_printf("\n");
}

void	tstr_repeat(void)
{
	t_string str;

	str = ft_tstr_new(0);
	ft_tstr_repeat(&str, " ", 4);
	if (ft_strcmp(str.data, "    ") == 0)
		ft_printf(GREEN "1.OK " RESET);
	else
		ft_printf(RED "\nFAILED: repeat(\" \", 4) -> got: \"%s\"\n" RESET, str.data);
	ft_tstr_clear(&str);
	ft_tstr_repeat(&str, "ab", 3);
	if (ft_strcmp(str.data, "ababab") != 0)
		ft_printf(RED "\nFAILED: repeat(\"ab\", 3) -> got: \"%s\"\n" RESET, str.data);
	else
		ft_printf(GREEN "2.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_repeat(&str, "", 5);
	if (str.len != 0)
		ft_printf(RED "\nFAILED: repeat(\"\", 5) -> expected empty, got: \"%s\"\n" RESET, str.data);
	else
		ft_printf(GREEN "3.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_repeat(&str, "fail", 0);
	if (str.len != 0)
		ft_printf(RED "\nFAILED: repeat(\"fail\", 0) -> expected empty, got: \"%s\"\n" RESET, str.data);
	else
		ft_printf(GREEN "4.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_repeat(&str, NULL, 4);
	if (str.len != 0)
		ft_printf(RED "\nFAILED: repeat(NULL, 4) -> expected empty, got: \"%s\"\n" RESET, str.data);
	else
		ft_printf(GREEN "5.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_repeat(NULL, "ghost", 2);
	ft_printf(GREEN "6.OK" RESET "\n");

	ft_tstr_free(&str);
}


void	tstr_insert(void)
{
	t_string	str;

	str = ft_tstr_from_cstr("Hello!");
	ft_tstr_insert(&str, " there", 5);
	if (ft_strcmp(str.data, "Hello there!") != 0 || str.len != 12)
		ft_printf(RED "\nFAILED: insert in middle -> got: \"%s\"\n" RESET, str.data);
	else if (str.alloc_size <= str.len)
		ft_printf(RED "\nFAILED: alloc_size too small -> alloc: %u, len: %u\n" RESET, str.alloc_size, str.len);
	else
		ft_printf(GREEN "1.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, "World");
	ft_tstr_insert(&str, "Hello ", 0);
	if (ft_strcmp(str.data, "Hello World") != 0)
		ft_printf(RED "\nFAILED: insert at beginning -> got: \"%s\"\n" RESET, str.data);
	else if (str.alloc_size <= str.len)
		ft_printf(RED "\nFAILED: alloc_size too small (begin) -> alloc: %u, len: %u\n" RESET, str.alloc_size, str.len);
	else
		ft_printf(GREEN "2.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, "Hello");
	ft_tstr_insert(&str, " World", str.len);
	if (ft_strcmp(str.data, "Hello World") != 0)
		ft_printf(RED "\nFAILED: insert at end -> got: \"%s\"\n" RESET, str.data);
	else if (str.alloc_size <= str.len)
		ft_printf(RED "\nFAILED: alloc_size too small (end) -> alloc: %u, len: %u\n" RESET, str.alloc_size, str.len);
	else
		ft_printf(GREEN "3.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, "Hello");
	ft_tstr_insert(&str, NULL, 3);
	if (ft_strcmp(str.data, "Hello") != 0)
		ft_printf(RED "\nFAILED: insert NULL -> got: \"%s\"\n" RESET, str.data);
	else
		ft_printf(GREEN "4.OK " RESET);
	ft_tstr_clear(&str);

	ft_tstr_pushstr(&str, "Hi");
	ft_tstr_insert(&str, "oops", 50);
	if (ft_strcmp(str.data, "Hi") != 0)
		ft_printf(RED "\nFAILED: insert out-of-bounds -> got: \"%s\"\n" RESET, str.data);
	else
		ft_printf(GREEN "5.OK " RESET);
	ft_tstr_free(&str);

	ft_tstr_insert(NULL, "ghost", 0);
	ft_printf(GREEN "6.OK" RESET "\n");
}


int main(void)
{
	ft_printf(PURPLE "TSTR_NEW: " RESET); tstr_new();
	ft_printf(PURPLE "TSTR_PUSH: " RESET); tstr_push_test();
	ft_printf(PURPLE "TSTR_PUSHSTR: " RESET); tstr_pushstr_test();
	ft_printf(PURPLE "TSTR_BORROW: " RESET); tstr_borrow_test();
	ft_printf(PURPLE "TSTR_FROM_CSTR: " RESET); tstr_from_cstr_test();
	ft_printf(PURPLE "TSTR_CLEAR: " RESET); tstr_from_cstr_clear();
	ft_printf(PURPLE "TSTR_FIT: " RESET); tstr_fit();
	ft_printf(PURPLE "TSTR_INSTR: " RESET); tstr_instr();
	ft_printf(PURPLE "TSTR_TRIM: " RESET); tstr_trim();
	ft_printf(PURPLE "TSTR_RESERVE: " RESET); tstr_reserve();
	ft_printf(PURPLE "TSTR_POP: " RESET); tstr_pop();
	ft_printf(PURPLE "TSTR_REPEAT: " RESET); tstr_repeat();
	ft_printf(PURPLE "TSTR_INSERT: " RESET); tstr_insert();
	return (0);
}
