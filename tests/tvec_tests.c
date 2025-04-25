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

int main(void)
{
    ft_printf(PURPLE "VEC_NEW: " RESET); vec_new_test();
    ft_printf(PURPLE "VEC_PUSH: " RESET); vec_push_test();
    ft_printf(PURPLE "VEC_FREE: " RESET); vec_free_test();
    ft_printf(PURPLE "VEC_EDGE: " RESET); vec_edge_cases();
    return (0);
}
