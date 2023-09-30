/*
 *  author:
 *      indestinee
 *  date:
 *      2019/05/24
 *  file name:
 *      bit.cpp
 */

#include <bits/stdc++.h>
using namespace std;

/* @Binary Indexed Tree {{{
 * single point modify, prefix query 
 */
inline int lowbit(const int &x) {
    return -x & x;
}
inline void modify(int x, int *c, int d = 1) {
    while (x < maxn) {
        c[x] += d;
        x += lowbit(x);
    }
}
inline int query(int x, int *c) {
    int ret = 0;
    while (x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
/* }}} */

/* @Binary Indexed Tree {{{
 * prefix modify, single point query
 */
inline int lowbit(const int &x) {
    return -x & x;
}
inline void modify(int x, int *c, int d = 1) {
    while (x) {
        c[x] += d;
        x -= lowbit(x);
    }
}
inline int query(int x, int *c) {
    int ret = 0;
    while (x < maxn) {
        ret += c[x];
        x += lowbit(x);
    }
    return ret;
}
/* }}} */
int main() {


    return 0;
}
