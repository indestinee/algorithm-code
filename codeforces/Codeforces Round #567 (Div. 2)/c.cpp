/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/17
 *  file name:
 *      c.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, s[maxn][maxn];
char a[maxn][maxn];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            s[i][j] = (j && a[i][j] == a[i][j-1]) ? s[i][j-1] : j;

    long long ans = 0;
    for (int r = 0; r < m; r++) {
        int i = 0, j, k, l;
        map<int, int> left;
        for (j = i; j < n && a[i][r] == a[j][r]; j++)
            left[s[j][r]] += 1;

        for (k = j; k < n && a[k][r] == a[j][r]; k++)
            left[s[k][r]] += 1;

        for (l = k; l < n && a[k][r] == a[l][r] && l - k < k - j; l++)
            left[s[l][r]] += 1;

        while (k < n) {
            while (k - j < j - i) {
                if (--left[s[i][r]] == 0)
                    left.erase(s[i][r]);
                i++;
            }

            if (l - k == k - j && k - j == j - i)
                ans += r-left.rbegin()->first+1;

            for (; i < j; i++)
                if (--left[s[i][r]] == 0)
                    left.erase(s[i][r]);

            for (; l < n && a[k][r] == a[l][r]; l++)
                left[s[l][r]] += 1;

            i = j; j = k; k = l;
            for (l = k; l < n && a[k][r] == a[l][r] && l - k < k - j; l++)
                left[s[l][r]] += 1;

        }
    }

    cout << ans << endl;


    return 0;
}
