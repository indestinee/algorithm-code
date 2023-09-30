/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (34.05%)
 * Total Accepted:    45.7K
 * Total Submissions: 134.1K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 * 
 * Note:
 * Rotation is not allowed.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3 
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

template<typename T>
inline void discretization(vector<T> &v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}
template<typename T>
inline void discretization(T *v, int &n) {
    sort(v, v + n);
    n = unique(v, v + n) - v;
}

const int maxn = 1e5 + 10;
int c[maxn];

/* @binary indexed tree {{{
 * single point modify, prefix query 
 */
inline int lowbit(const int &x) {
    return -x & x;
}
inline void modify(int x, int *c, int d = 1) {
    while (x < maxn) {
        c[x] = max(c[x], d);
        x += lowbit(x);
    }
}
inline int query(int x, int *c) {
    int ret = 0;
    while (x) {
        ret = max(ret, c[x]);
        x -= lowbit(x);
    }
    return ret;
}
/* }}} */

inline bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> v;
        for (auto p: envelopes)
            v.push_back(p[1]);
        discretization<int> (v);
        
        memset(c, 0, (v.size() + 1) << 2);
        sort(envelopes.begin(), envelopes.end(), cmp);
        int ans = 0;

        for (auto p: envelopes) {
            int cur = lower_bound(v.begin(), v.end(), p[1]) - v.begin() + 1, val = query(cur - 1, c) + 1;  
            modify(cur, c, val);

            ans = max(ans, val);

        }

        return ans;
    
    }
};
