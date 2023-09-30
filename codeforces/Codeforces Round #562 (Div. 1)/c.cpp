/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/03
 *  file name:
 *      c.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10, maxq = maxn, maxb = log2(maxn)+1;

struct query{
    int l, r, id;
    inline int in(int _id) {
        id = _id;
        int res = scanf("%d%d", &l, &r);
        l--, r--;
        return res;
    }
    friend inline bool operator < (const query &a, const query &b) {
        return a.r < b.r;
    }
} q[maxq];

int n, m, a[maxn], ans[maxq], tmp[maxb], b[maxn][maxb], last[maxb];

inline void update(const int &i) {
    int cnt = 0;

    for (int j = 0; j < maxb; j++)
        if (a[i] & (1<<j))
            tmp[cnt++] = j;

    for (int j = 0; j < maxb; j++) {
        if ((a[i] & (1<<j)) == 0) {

            for (int k = 0; k < cnt; k++) {
                if (last[tmp[k]] == -1)
                    continue;
                b[i][j] = max(b[i][j], b[last[tmp[k]]][j]);
            }
        }
    }

    for (int k = 0; k < cnt; k++) {
        b[i][tmp[k]] = i;
        last[tmp[k]] = i;
    }
}

inline bool query(const query &q) {
    for (int j = 0; j < maxb; j++)
        if ((a[q.l] & (1 << j)) && b[q.r][j] >= q.l)
            return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    for (int i = 0; i < m; i++)
        q[i].in(i);

    memset(last, -1, sizeof last);
    memset(b, -1, sizeof b);

    sort(q, q + m);


    for (int _ = 0, i = 0; _ < m; _++) {
        auto cur = q[_];
        while (i <= cur.r)
            update(i++);
        #ifdef DEBUG
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < maxb; k++)
                printf("%d ", b[j][k]);
            puts("");
        }
        puts("-----------------");
        #endif
        ans[cur.id] = query(cur);
    }


    for (int i = 0; i < m; i++)
        puts(ans[i]?"Shi":"Fou");

    return 0;
}
