#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    find_obs(int n, int **map, int ***nbr)
{
    int i;
    int j;
    int cnt;

    *nbr = (int **)malloc(sizeof(int *) * 2);
    (*nbr)[0] = (int *)malloc(sizeof(int) * (n * n + 1));
    (*nbr)[1] = (int *)malloc(sizeof(int) * (n * n + 1));
    i = -1;
    cnt = 0;
    while (++i < n)
    {
        j = -1;
        while (++j < n)
        {
            if (map[i][j] == 1)
            {
                (*nbr)[0][cnt] = j;    /*x-axis of obs0tacle*/
                (*nbr)[1][cnt] = i;    /*y-axis of obstacle*/
                cnt++;
            }
        }
    }
    (*nbr)[0][cnt] = -1;
    (*nbr)[1][cnt] = -1;
}

int max(int n, int a, int b, int *xy)
{
    int dx;
    int dy;

    if (a < 0 || b < 0)
    {
        dx = n - xy[0];
        dy = n - xy[1];
        if (dx > dy)
            return (dy);
        return (dx);
    }
    else if (a > b)
        return (a);
    else
        return (b);
}

int dist(int n, int *xy, int **nbr)
{
    int i;
    int mm;
    int carry;
    int j;

    mm = max(n, n - xy[0], n - xy[1], xy);
    i = 0;
    j = -1;
    while (nbr[0][i] != -1)
    {
        carry = max(n, nbr[0][i] - xy[0], nbr[1][i] - xy[1], xy);
        if (carry < mm)
        {
            mm = carry;
            j = i;
        }
        i++;
    }
    return (mm);
}

int maxsq(int n, int **nbr, int *m)
{
    int i;
    int j;
    int xy[2];
    int mm;
    int carry;

    mm = -1;
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            xy[0] = j;
            xy[1] = i;
            carry = dist(n, xy, nbr);
            if (carry > mm)
            {
                m[0] = j;
                m[1] = i;
                mm = carry;
            }
            j++;
        }
        i++;
    }
    return (mm);
}