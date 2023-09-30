/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/03
 *  file name:
 *      a.cpp
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;

int n, m, a[maxn];
inline bool ok(const int &k) {
    int mini = 0;

    for (int i = 0; i < n; i++) {
        if (mini > a[i] + k)
            return false;

        if (a[i] + k >= m && mini <= (a[i] + k) % m)
            continue;

        mini = max(mini, a[i]);
    }
    return true;

}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = 0, r = m, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", l);
    return 0;
}
