/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/12
 *  file name:
 *      b.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int r[maxn], c[maxn], n, m;

char a[maxn][maxn];

bool work() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            r[i] += a[i][j] == '*';
            c[j] += a[i][j] == '*';
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        if (r[x] < r[i])
            x = i;
    for (int j = 0; j < m; j++)
        if (c[y] < c[j])
            y = j;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i != x && j != y && a[i][j] == '*')
                return false;


    for (int i = x+1; i < n; i++)
        if (a[i][y] == '*' && a[i-1][y] == '.')
            return false;

    for (int i = x-1; i > -1; i--)
        if (a[i][y] == '*' && a[i+1][y] == '.')
            return false;

    for (int j = y+1; j < m; j++)
        if (a[x][j] == '*' && a[x][j-1] == '.')
            return false;

    for (int j = y-1; j > -1; j--)
        if (a[x][j] == '*' && a[x][j+1] == '.')
            return false;

    return x != 0 && y != 0 && x != n-1 && y != m-1 && a[x][y-1] == '*' && a[x-1][y] == '*' && a[x+1][y] == '*' && a[x][y+1] == '*' && a[x][y] == '*';
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf("%s", a[i]);

    printf(work()?"YES\n":"NO\n");


    return 0;
}
