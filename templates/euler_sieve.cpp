/*
 *  author:
 *      indestinee
 *  date:
 *      2019/05/24
 *  file name:
 *      euler_sieve.cpp
 */

#include <bits/stdc++.h>
using namespace std;

/* @ euler sieve, finding all primes in range [2, maxn) {{{ */
const int prime_maxn = 1e4 + 10;
int prime[prime_maxn], prime_cnt = 0;
bool prime_vis[prime_maxn];
void euler() {
    for (int i = 2; i < prime_maxn; i++) {
        if (!prime_vis[i])
            prime[prime_cnt++] = i;
        for (int j = 0; j < prime_cnt && i*prime[j] < prime_maxn; j++) {
            prime_vis[i*prime[j]]  = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
/* }}} */

int main() {
    euler();
    for (int i = 0; i < 100; i++)
        printf("%d ", prime[i]);


    return 0;
}
/* @manacher {{{ */
template<typename T> 
void manacher(const T* arr, const int n, int *len) {
    len[0] = 1;
    for (int i = 1, j = 0; i < (n<<1)-1; i++) {
        int p = i >> 1, q = i - p, r = ((j+1) >> 1) + len[j] - 1;
        len[i] = r < q ? 0 : min(r - q + 1, len[(j<<1)-i]);
        while (p - len[i] >= 0 && q + len[i] < n &&
                arr[p-len[i]] == arr[q+len[i]])
            len[i]++;
        if (q + len[i] - 1 > r)
            j = i;
    }
}
/* }}} */
