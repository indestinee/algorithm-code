/*
 *  author:
 *      indestinee
 *  date:
 *      2019/05/25
 *  file name:
 *      test.cpp
 */

#include <bits/stdc++.h>
using namespace std;

/* @quick pow: x**b {{{ */
template<typename T>
inline T quick_pow(T x, long long b) {
    T res = T(1);
    while (b) {
        if (b & 1)
            res = res * x % mod;
        x = x * x;
    }
    return res;
}
/*}}}*/
int main() {
    int cas;
    scanf("%d", &cas);
    for (int _cas = 1; _cas <= cas; _cas++) {
        
    
        printf("Case #%d: \n", _cas);
    }

    int n;
    while (~scanf("%d", &n)) {
        
    }
    
    


    return 0;
}
