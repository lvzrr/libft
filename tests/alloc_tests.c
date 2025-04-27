/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:17:55 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 04:50:00 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"
#include "printf.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

void    alloc_basic_test(void);
void    alloc_calloc_test(void);
void    alloc_realloc_test(void);
void    alloc_recalloc_test(void);
void    alloc_free_test(void);

void alloc_basic_test(void)
{
    char *ptr = ft_talloc(10, "basic_test");
    void *tmp = ptr;

    if (!ptr)
        ft_printf(RED "\nFAILED: basic ft_talloc returned NULL\n" RESET);
    else
        ft_printf(GREEN "1.OK " RESET);
    ft_free(&tmp);
    ptr = NULL;
}

void alloc_calloc_test(void)
{
    char *ptr = ft_calloc(10, sizeof(char));
    void *tmp = ptr;
    int i;
    int fail = 0;

    if (!ptr)
        fail = 1;
    else
    {
        for (i = 0; i < 10; i++)
        {
            if (ptr[i] != 0)
            {
                fail = 1;
                break;
            }
        }
    }
    if (fail)
        ft_printf(RED "\nFAILED: ft_calloc zeroing or allocation\n" RESET);
    else
        ft_printf(GREEN "1.OK " RESET);
    ft_free(&tmp);
    ptr = NULL;
}

void alloc_realloc_test(void)
{
    char *ptr = ft_talloc(5, "realloc_test");
    void *tmp;
    int i;

    if (!ptr)
    {
        ft_printf(RED "\nFAILED: initial ft_talloc failed\n" RESET);
        return;
    }
    for (i = 0; i < 5; i++)
        ptr[i] = (char)('a' + i);

    ptr = ft_realloc(ptr, 5, 10);
    if (!ptr)
    {
        ft_printf(RED "\nFAILED: ft_realloc returned NULL\n" RESET);
        return;
    }
    for (i = 0; i < 5; i++)
    {
        if (ptr[i] != (char)('a' + i))
        {
            ft_printf(RED "\nFAILED: ft_realloc lost old data\n" RESET);
            tmp = ptr;
            ft_free(&tmp);
            ptr = NULL;
            return;
        }
    }
    ft_printf(GREEN "1.OK " RESET);
    tmp = ptr;
    ft_free(&tmp);
    ptr = NULL;
}

void alloc_recalloc_test(void)
{
    char *ptr = ft_talloc(5, "recalloc_test");
    void *tmp;
    int i;

    if (!ptr)
    {
        ft_printf(RED "\nFAILED: initial ft_talloc failed\n" RESET);
        return;
    }
    for (i = 0; i < 5; i++)
        ptr[i] = (char)('A' + i);

    ptr = ft_recalloc(ptr, 5, 10);
    if (!ptr)
    {
        ft_printf(RED "\nFAILED: ft_recalloc returned NULL\n" RESET);
        return;
    }
    for (i = 0; i < 5; i++)
    {
        if (ptr[i] != (char)('A' + i))
        {
            ft_printf(RED "\nFAILED: ft_recalloc lost old data\n" RESET);
            tmp = ptr;
            ft_free(&tmp);
            ptr = NULL;
            return;
        }
    }
    for (i = 5; i < 10; i++)
    {
        if (ptr[i] != 0)
        {
            ft_printf(RED "\nFAILED: ft_recalloc did not zero new memory\n" RESET);
            tmp = ptr;
            ft_free(&tmp);
            ptr = NULL;
            return;
        }
    }
    ft_printf(GREEN "1.OK " RESET);
    tmp = ptr;
    ft_free(&tmp);
    ptr = NULL;
}

void alloc_free_test(void)
{
    char *ptr = ft_talloc(10, "free_test");
    void *tmp = ptr;

    if (!ptr)
    {
        ft_printf(RED "\nFAILED: ft_talloc for ft_free_test\n" RESET);
        return;
    }
    ft_free(&tmp);
    if (tmp != NULL)
        ft_printf(RED "\nFAILED: ft_free did not NULL the pointer\n" RESET);
    else
        ft_printf(GREEN "1.OK " RESET);
}


void    alloc_gc_test(void);

void alloc_gc_test(void)
{
    t_map *tmp;

    tmp = g_table;
    if (!tmp)
    {
        ft_printf(RED "\nFAILED: no g_table before GC\n" RESET);
        return;
    }
    ft_gc();
    if (g_table != NULL)
        ft_printf(RED "\nFAILED: g_table not NULL after GC\n" RESET);
    else
	{
		ft_printf(GREEN "1.OK " RESET);
	}
	
	ft_talloc(2034, "test");
}

int main(void)
{
	ft_talloc(9999, "alloc early on");
    ft_printf(PURPLE "ALLOC_BASIC: " RESET);
    alloc_basic_test();
    ft_printf("\n");
    ft_printf(PURPLE "ALLOC_CALLOC: " RESET);
    alloc_calloc_test();
    ft_printf("\n");
    ft_printf(PURPLE "ALLOC_REALLOC: " RESET);
    alloc_realloc_test();
    ft_printf("\n");
    ft_printf(PURPLE "ALLOC_RECALLOC: " RESET);
    alloc_recalloc_test();
    ft_printf("\n");
    ft_printf(PURPLE "ALLOC_FREE: " RESET);
    alloc_free_test();
    ft_printf("\n");
    ft_printf(PURPLE "GC: " RESET);
	alloc_gc_test();
    ft_printf("\n");
	ft_printf(PURPLE "GC (ON EXIT) - NO CRASH = GOOD " RESET);
	ft_talloc(10000000, "alloc early on");
    ft_printf("\n");
    return (0);
}
