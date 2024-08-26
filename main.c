/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokim2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 06:11:38 by hokim2            #+#    #+#             */
/*   Updated: 2024/08/26 06:11:43 by hokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bsq.h"
#include <math.h>

int main(void)
{
    srand(time(NULL));
    int n = 1000;
    int **map;
    int **nbr;
    int m[2];
    int mm;

    map = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        map[i] = (int *)malloc(n * sizeof(int));
    }
    int ran;
    int p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ran = rand() % (n * n);
            if (ran < n * log2(n))
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //if (i == -1)
                //printf("%d", j);
            //else if (j == -1)
                //printf("%d", i);
            //else
                printf("%d", map[i][j]);
        }
        printf("\n");
    }
    find_obs(n, map, &nbr);
    for (int i = 0; nbr[0][i] != -1; i++)
    {
        printf("%d : (%2d, %2d)\n", i, *(*(nbr) + i), nbr[1][i]);
    }
    mm = maxsq(n, nbr, m);
    printf("MAX DIST = %d, MAX AT (%d, %d)\n", mm, m[0], m[1]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[0] <= j && j < m[0] + mm && m[1] <= i && i < m[1] + mm)
                printf("/");
            //else if (i == -1)
                //printf("%d", j);
            //else if (j == -1)
                //printf("%d", i);
            else
                printf("%d", map[i][j]);
        }
        printf("\n");
    }
    return (0);
}