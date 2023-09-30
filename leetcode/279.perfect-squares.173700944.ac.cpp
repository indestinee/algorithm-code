#include <bits/stdc++.h>
using namespace std;
const int bound = 10000, inf = 1e9 + 7;
int f[bound];
inline int sqr(const int &x) {
    return x * x;
}
inline int dfs(int x, int ans=0) {
    if (x < bound) 
        return ans + f[x];
    int i = sqrt(x + 0.5), res = inf;
    for (int j = 0; j < 1 && i - j > 0; j++)
        res = min(res, dfs(x - sqr(i-j), ans + 1));
    return res;
}
class Solution {
public:
    int numSquares(int n) {
        if (f[1] == 0) {
            memset(f, 0x3f, sizeof f);
            f[0] = 0;
            for (int i = 0; i < bound; i++) {
                for (int j = 1;; j++) {
                    int x = i + sqr(j);
                    if (x >= bound)
                        break;
                    f[x] = min(f[x], f[i] + 1);
                }
            }
        }
        return dfs(n);
    }
};
