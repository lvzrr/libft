/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 07:20:19 by jaicastr          #+#    #+#             */
/*   Updated: 2025/04/27 07:20:23 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "printf.h"
#include "alloc.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

void    map_init_test(void);
void    map_insert_test(void);
void    map_lookup_test(void);
void    map_edge_cases_test(void);

void map_init_test(void)
{
	t_map *map = ft_map_init();
	if (!map || map->keys.size != 0 || map->values.size != 0 || map->tags.size != 0)
		ft_printf(RED "\nFAILED: map init structure\n" RESET);
	else
		ft_printf(GREEN "1.OK " RESET);
	ft_map_free(map);
}

void map_insert_test(void)
{
	t_map *map = ft_map_init();
	int *x = ft_alloc(sizeof(int));
	*x = 42;
	if (ft_map_insert(x, sizeof(int), map, "x_tag") != 1)
		ft_printf(RED "\nFAILED: map insert basic\n" RESET);
	else
		ft_printf(GREEN "1.OK " RESET);
	ft_map_free(map);
}

void map_lookup_test(void)
{
	t_map *map = ft_map_init();
	int *x = ft_alloc(sizeof(int));
	int *y = ft_alloc(sizeof(int));
	*x = 42;
	*y = 7;

	ft_map_insert(x, sizeof(int), map, "x_tag");
	ft_map_insert(y, sizeof(int), map, "y_tag");

	t_mem *mem_x = ft_map_lookup(map, (size_t)x >> 4);
	t_mem *mem_y = ft_map_lookup(map, (size_t)y >> 4);
	t_mem *mem_null = ft_map_lookup(map, (size_t)0xdeadbeef >> 4);

	if (!mem_x || mem_x->ptr != x)
		ft_printf(RED "\nFAILED: lookup x (x = %p, mem_x = %p)\n" RESET, (void *)x, mem_x ? mem_x->ptr : NULL);
	else
		ft_printf(GREEN "1.OK " RESET);

	if (!mem_y || mem_y->ptr != y)
		ft_printf(RED "\nFAILED: lookup y (y = %p, mem_y = %p)\n" RESET, (void *)y, mem_y ? mem_y->ptr : NULL);
	else
		ft_printf(GREEN "2.OK " RESET);

	if (mem_null != NULL)
		ft_printf(RED "\nFAILED: lookup non-existent\n" RESET);
	else
		ft_printf(GREEN "3.OK " RESET);

	ft_map_free(map);
}

void map_edge_cases_test(void)
{
	t_map *map = ft_map_init();

	if (ft_map_insert(NULL, sizeof(int), NULL, "null_map") != -1)
		ft_printf(RED "\nFAILED: insert NULL map\n" RESET);
	else
		ft_printf(GREEN "1.OK " RESET);

	if (ft_map_insert(NULL, 0, map, "null_data") != -1)
		ft_printf(RED "\nFAILED: insert NULL data\n" RESET);
	else
		ft_printf(GREEN "2.OK " RESET);

	int *dummy = ft_alloc(sizeof(int));
	*dummy = 1;
	if (ft_map_insert(dummy, sizeof(int), map, NULL) != 1)
		ft_printf(RED "\nFAILED: insert NULL tag\n" RESET);
	else
		ft_printf(GREEN "3.OK " RESET);

	int *dummy2 = ft_alloc(sizeof(int));
	*dummy2 = 2;
	if (ft_map_insert(dummy2, sizeof(int), map, "") != 1)
		ft_printf(RED "\nFAILED: insert empty tag\n" RESET);
	else
		ft_printf(GREEN "4.OK " RESET);

	char *big = ft_alloc(4096);
	if (!big)
		ft_printf(RED "\nFAILED: ft_alloc big data\n" RESET);
	else
	{
		if (ft_map_insert(big, 4096, map, "big_data") != 1)
			ft_printf(RED "\nFAILED: insert big data\n" RESET);
		else
			ft_printf(GREEN "5.OK " RESET);
	}

	if (ft_map_lookup(map, (size_t)0x12345678 >> 4) != NULL)
		ft_printf(RED "\nFAILED: lookup non-existent key\n" RESET);
	else
		ft_printf(GREEN "6.OK " RESET);

	ft_map_free(map);
}

int main(void)
{
	ft_printf(PURPLE "MAP_INIT: " RESET);
	map_init_test();
	ft_printf("\n");

	ft_printf(PURPLE "MAP_INSERT: " RESET);
	map_insert_test();
	ft_printf("\n");

	ft_printf(PURPLE "MAP_LOOKUP: " RESET);
	map_lookup_test();
	ft_printf("\n");

	ft_printf(PURPLE "MAP_EDGE_CASES: " RESET);
	map_edge_cases_test();
	ft_printf("\n");

	return (0);
}
