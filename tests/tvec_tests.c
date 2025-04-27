/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tvec_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:02:34 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/25 15:00:00 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "printf.h"
#include <stdlib.h>
#include <limits.h>

#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define PURPLE  "\033[0;35m"
#define RESET   "\033[0m"

#ifndef BIG_TEST
# define BIG_TEST 0
#endif

void    vec_new_test(void);
void    vec_push_test(void);
void    vec_free_test(void);
void    vec_edge_cases(void);
void	vec_reserve_test(void);
void	vec_pop_test(void);
void	vec_clear_test(void);
void	vec_fit_test(void);
void	vec_insert_test(void);

void    vec_new_test(void)
{
    t_vec v;

    v = ft_vec(10, sizeof(int));
    if (v.alloc_size != 10 || v.size != 0 || !v.data || v.sizeof_type != sizeof(int))
        ft_printf(RED "\nFAILED: ft_vec(10, sizeof(int))\n" RESET);
    else
        ft_printf(GREEN "1.OK " RESET);
    ft_vec_free(&v);

    v = ft_vec(0, sizeof(int));
    if (v.data || v.alloc_size != 0 || v.size != 0)
        ft_printf(RED "\nFAILED: ft_vec(0, sizeof(int))\n" RESET);
    else
        ft_printf(GREEN "2.OK " RESET);

    v = ft_vec(10, 0);
    if (v.data || v.alloc_size != 0 || v.size != 0)
        ft_printf(RED "\nFAILED: ft_vec(10, 0)\n" RESET);
    else
	{
		ft_printf(GREEN "3.OK " RESET);
	}

	ft_vec_free(&v);
	if (BIG_TEST)
	{
		v = ft_vec(INT_MAX, 1);
		if (!v.data || v.alloc_size != INT_MAX || v.size != 0)
			ft_printf(RED "\nFAILED: ft_vec(INT_MAX, 1) -> %u | %u\n" RESET, v.alloc_size, v.size);
		else
			ft_printf(GREEN "4.OK " RESET);
		ft_vec_free(&v);
	}

    ft_printf("\n");
}


void	vec_push_test(void)
{
	t_vec	v = ft_vec(2, sizeof(int));
	int		a = 42, b = 7, c = 9, d = -1, e = 0xABCDEF;
	int		massive[1000];
	int		*arr;
	int		pass = 1;

	ft_vec_push(&v, &a, 1);
	ft_vec_push(&v, &b, 1);
	ft_vec_push(&v, &c, 1);
	ft_vec_push(&v, &d, 1);
	ft_vec_push(&v, &e, 1);
	arr = (int *)v.data;

	if (v.size != 5 || arr[0] != 42 || arr[1] != 7 || arr[2] != 9 || arr[3] != -1 || arr[4] != 0xABCDEF)
		ft_printf(RED "\nFAILED: push 5 ints -> got: %d %d %d %d %x\n" RESET, arr[0], arr[1], arr[2], arr[3], arr[4]);
	else
		ft_printf(GREEN "1.OK " RESET);

	ft_vec_push(NULL, &a, 1);
	ft_printf(GREEN "2.OK " RESET);
	ft_vec_push(&v, NULL, 1);
	ft_printf(GREEN "3.OK " RESET);
	ft_vec_push(NULL, NULL, 1);
	ft_printf(GREEN "4.OK " RESET);
	ft_vec_push(&v, &a, 0);
	ft_printf(GREEN "5.OK " RESET);

	for (int i = 0; i < 1000; i++)
		massive[i] = i * 2;
	ft_vec_push(&v, massive, 1000);

	if (v.size < 1005)
		ft_printf(RED "\nFAILED: push large chunk -> size too small: %u\n" RESET, v.size);
	else
		ft_printf(GREEN "6.OK " RESET);

	arr = (int *)v.data;
	for (int i = 0; i < 1000; i++)
		if (arr[i + 5] != i * 2)
			pass = 0;
	if (!pass || v.size != 1005)
		ft_printf(RED "\nFAILED: push large chunk content -> size: %u\n" RESET, v.size);
	else
		ft_printf(GREEN "7.OK " RESET);

	int max = INT_MAX;
	ft_vec_push(&v, &max, 1);
	if (((int *)v.data)[v.size - 1] != INT_MAX)
		ft_printf(RED "\nFAILED: push INT_MAX -> got: %d\n" RESET, ((int *)v.data)[v.size - 1]);
	else
		ft_printf(GREEN "8.OK " RESET);

	ft_vec_push(&v, &((int *)v.data)[0], 2);
		if (((int *)v.data)[v.size - 2] != 42 || ((int *)v.data)[v.size - 1] != 7)
			ft_printf(RED "\nFAILED: self-overlap push -> got: %d %d\n" RESET,
				((int *)v.data)[v.size - 2], ((int *)v.data)[v.size - 1]);
		else
			ft_printf(GREEN "9.OK " RESET);

	ft_vec_free(&v);
	ft_printf("\n");
}

void    vec_free_test(void)
{
    t_vec v = ft_vec(5, sizeof(int));
    ft_vec_free(&v);

    if (v.data != NULL || v.size != 0 || v.alloc_size != 0)
        ft_printf(RED "\nFAILED: ft_vec_free() -> data not cleared\n" RESET);
    else
        ft_printf(GREEN "1.OK " RESET);

    ft_vec_free(NULL);
    ft_printf(GREEN "2.OK" RESET "\n");
}

void	vec_reserve_test(void)
{
	t_vec	v = ft_vec(2, sizeof(int));
	int		*arr;
	int		a = 1234;

	// 1. Basic reserve
	ft_vec_reserve(&v, 10);
	if (v.alloc_size < 10)
		ft_printf(RED "\nFAILED: reserve 10 -> got: %u\n" RESET, v.alloc_size);
	else
		ft_printf(GREEN "1.OK " RESET);

	// 2. Reserve smaller than current → no change
	size_t prev = v.alloc_size;
	ft_vec_reserve(&v, 5);
	if (v.alloc_size != prev)
		ft_printf(RED "\nFAILED: reserve 5 -> should not change alloc_size (was %u, got %u)\n" RESET, prev, v.alloc_size);
	else
		ft_printf(GREEN "2.OK " RESET);

	// 3. NULL input
	ft_vec_reserve(NULL, 10);
	ft_printf(GREEN "3.OK " RESET);

	// 4. Zero reserve
	ft_vec_reserve(&v, 0);
	ft_printf(GREEN "4.OK " RESET);

	// 5. Push after reserve
	ft_vec_push(&v, &a, 1);
	arr = (int *)v.data;
	if (arr[0] != 1234)
		ft_printf(RED "\nFAILED: push after reserve -> got: %d\n" RESET, arr[0]);
	else
		ft_printf(GREEN "5.OK " RESET);

	// 6. Large reserve
	ft_vec_reserve(&v, 1000000);
	if (v.alloc_size < 1000000)
		ft_printf(RED "\nFAILED: large reserve -> got: %u\n" RESET, v.alloc_size);
	else
		ft_printf(GREEN "6.OK " RESET);

	ft_vec_free(&v);
	ft_printf("\n");
}

void    vec_edge_cases(void)
{
    t_vec v = ft_vec(1, sizeof(int));
    int i;
    for (i = 0; i < 1000; i++)
        ft_vec_push(&v, &i, 1);
    int *arr = (int *)v.data;
    int ok = 1;
    for (i = 0; i < 1000; i++)
        if (arr[i] != i)
            ok = 0;

    if (!ok || v.size != 1000)
        ft_printf(RED "\nFAILED: edge loop push -> last: %d\n" RESET, arr[999]);
    else
        ft_printf(GREEN "1.OK " RESET);
    ft_vec_free(&v);
    ft_printf("\n");
}


void	vec_pop_test(void)
{
	t_vec	v = ft_vec(5, sizeof(int));
	int		values[] = {1, 2, 3, 4, 5};
	int		pass = 1;

	ft_vec_push(&v, values, 5);

	for (int i = 4; i >= 0; i--)
	{
		int *p = (int *)ft_vec_pop(&v);
		if (!p || *p != values[i])
		{
			ft_printf(RED "\nFAILED: vec_pop at %d -> got: %d expected: %d\n" RESET,
				i, p ? *p : -999, values[i]);
			pass = 0;
		}
		free(p);
	}

	if (v.size != 0)
	{
		ft_printf(RED "\nFAILED: vec_pop size after all pops -> %u\n" RESET, v.size);
		pass = 0;
	}
	if (pass)
		ft_printf(GREEN "1.OK " RESET);

	void *null = ft_vec_pop(NULL);
	void *empty = ft_vec_pop(&v);
	if (null != NULL || empty != NULL)
		ft_printf(RED "\nFAILED: vec_pop NULL and empty cases\n" RESET);
	else
		ft_printf(GREEN "2.OK" RESET "\n");

	ft_vec_free(&v);
}

void	vec_fit_test(void)
{
	t_vec	v = ft_vec(10, sizeof(int));
	int		arr[] = {1, 2, 3, 4, 5};
	int		*data;
	int		pass = 1;

	// Push 5 elements into alloc 10
	ft_vec_push(&v, arr, 5);
	if (v.alloc_size != 10)
		ft_printf(RED "\nFAILED: pre-fit alloc_size != 10 -> %u\n" RESET, v.alloc_size);
	else
		ft_printf(GREEN "1.OK " RESET);

	// Shrink
	ft_vec_fit(&v);
	if (v.alloc_size != 5 || v.size != 5)
		ft_printf(RED "\nFAILED: post-fit -> alloc_size: %u | size: %u\n" RESET, v.alloc_size, v.size);
	else
		ft_printf(GREEN "2.OK " RESET);

	// Data still correct?
	data = (int *)v.data;
	for (int i = 0; i < 5; i++)
		if (data[i] != arr[i])
			pass = 0;
	if (!pass)
		ft_printf(RED "\nFAILED: post-fit data mismatch\n" RESET);
	else
		ft_printf(GREEN "3.OK " RESET);

	// Call fit again: alloc == size, should be no-op
	ft_vec_fit(&v);
	if (v.alloc_size != 5 || v.size != 5)
		ft_printf(RED "\nFAILED: fit after fit -> alloc_size: %u\n" RESET, v.alloc_size);
	else
		ft_printf(GREEN "4.OK " RESET);

	// Empty vector test
	t_vec	empty = ft_vec(0, sizeof(int));
	ft_vec_fit(&empty); // shouldn't crash
	if (empty.data != NULL || empty.size != 0 || empty.alloc_size != 0)
		ft_printf(RED "\nFAILED: fit on empty vector\n" RESET);
	else
		ft_printf(GREEN "5.OK " RESET);
	ft_vec_free(&empty);

	// NULL test
	ft_vec_fit(NULL);
	ft_printf(GREEN "6.OK " RESET);

	// Garbage test: uninitialized-ish vector
	t_vec	junk = {0};
	junk.data = malloc(50);
	junk.size = 1;
	junk.alloc_size = 100;
	junk.sizeof_type = 1;
	ft_vec_fit(&junk);
	if (junk.alloc_size != junk.size)
		ft_printf(RED "\nFAILED: garbage vector shrink\n" RESET);
	else
		ft_printf(GREEN "7.OK " RESET);
	free(junk.data);

	// Final sanity check
	ft_vec_free(&v);
	ft_printf("\n");
}

void	vec_clear_test(void)
{
	t_vec	v = ft_vec(5, sizeof(int));
	int		input[] = {10, 20, 30, 40, 50};
	int		*arr;
	int		pass = 1;

	// Push 5 ints
	ft_vec_push(&v, input, 5);
	arr = (int *)v.data;

	// Call clear
	ft_vec_clear(&v);

	// Check size is reset
	if (v.size != 0)
	{
		ft_printf(RED "\nFAILED: vec_clear -> size is %u, expected 0\n" RESET, v.size);
		pass = 0;
	}

	// Check content is zeroed
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] != 0)
		{
			ft_printf(RED "\nFAILED: vec_clear -> index %d is not zero: %d\n" RESET, i, arr[i]);
			pass = 0;
			break;
		}
	}

	// Check NULL-safe
	ft_vec_clear(NULL);
	ft_printf(GREEN "1.OK " RESET);

	// Report final result
	if (pass)
		ft_printf(GREEN "2.OK\n" RESET);

	ft_vec_free(&v);
}

void	vec_insert_test(void)
{
	t_vec	v = ft_vec(5, sizeof(int));
	int		initial[] = {1, 2, 3, 4, 5};
	int		to_insert = 99;
	int		massive[1000];
	int		pass = 1;

	ft_vec_push(&v, initial, 5);

	// Insert in the middle
	ft_vec_insert(&v, 2, &to_insert, 1);
	int *arr = (int *)v.data;
	if (v.size != 6 || arr[2] != 99 || arr[3] != 3)
		ft_printf(RED "\nFAILED: insert middle -> size: %u arr[2]: %d\n" RESET, v.size, arr[2]);
	else
		ft_printf(GREEN "1.OK " RESET);

	// Insert at beginning
	to_insert = 77;
	ft_vec_insert(&v, 0, &to_insert, 1);
	arr = (int *)v.data;
	if (arr[0] != 77)
		ft_printf(RED "\nFAILED: insert beginning -> arr[0]: %d\n" RESET, arr[0]);
	else
		ft_printf(GREEN "2.OK " RESET);

	// Insert at end
	to_insert = 88;
	ft_vec_insert(&v, v.size, &to_insert, 1);
	arr = (int *)v.data;
	if (arr[v.size - 1] != 88)
		ft_printf(RED "\nFAILED: insert end -> arr[last]: %d\n" RESET, arr[v.size - 1]);
	else
		ft_printf(GREEN "3.OK " RESET);

	// Insert NULL
	ft_vec_insert(NULL, 0, &to_insert, 1);
	ft_vec_insert(&v, 0, NULL, 1);
	ft_vec_insert(NULL, 0, NULL, 1);
	ft_printf(GREEN "4.OK " RESET);

	// Insert with index too large
	ft_vec_insert(&v, v.size + 10, &to_insert, 1);
	ft_printf(GREEN "5.OK " RESET);

	// Bulk insert massive array
	for (int i = 0; i < 1000; i++)
		massive[i] = i;
	ft_vec_insert(&v, 3, massive, 1000);
	arr = (int *)v.data;
	for (int i = 0; i < 1000; i++)
		if (arr[3 + i] != i)
			pass = 0;
	if (!pass)
		ft_printf(RED "\nFAILED: bulk insert content mismatch\n" RESET);
	else
		ft_printf(GREEN "6.OK " RESET);

	// Check size after bulk insert
	if (v.size != 8 + 1000)
		ft_printf(RED "\nFAILED: bulk insert wrong size: %u\n" RESET, v.size);
	else
		ft_printf(GREEN "7.OK " RESET);

	// Insert 0 elements (should do nothing)
	ft_vec_insert(&v, 2, &to_insert, 0);
	if (v.size != 1008)
		ft_printf(RED "\nFAILED: insert 0 elements altered size\n" RESET);
	else
		ft_printf(GREEN "8.OK" RESET "\n");

	ft_vec_free(&v);
}

int main(void)
{
    ft_printf(PURPLE "VEC_NEW: " RESET); vec_new_test();
    ft_printf(PURPLE "VEC_PUSH: " RESET); vec_push_test();
    ft_printf(PURPLE "VEC_FREE: " RESET); vec_free_test();
    ft_printf(PURPLE "VEC_EDGE: " RESET); vec_edge_cases();
    ft_printf(PURPLE "VEC_RESERVE: " RESET); vec_reserve_test();
    ft_printf(PURPLE "VEC_POP: " RESET); vec_pop_test();
    ft_printf(PURPLE "VEC_CLEAR: " RESET); vec_clear_test();
    ft_printf(PURPLE "VEC_FIT: " RESET); vec_fit_test();
    ft_printf(PURPLE "VEC_INSERT: " RESET); vec_insert_test();
    return (0);
}
