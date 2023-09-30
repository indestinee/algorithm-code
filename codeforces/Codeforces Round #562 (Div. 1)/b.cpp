/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/03
 *  file name:
 *      b.cpp
 */

#include <bits/stdc++.h>
using namespace std;


int dfs(vector<int> v, int length=0) {
    for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {
            int k = j+j-i;
            if (k >= length)
                break;
            if (v[i] == v[j] && v[j] == v[k])
                return 0;
        }
    }
    int ans = length;
    v.push_back(0);
    ans = max(ans, dfs(v, length+1));
    *v.rbegin() = 1;
    ans = max(ans, dfs(v, length+1));
    v.pop_back();
    return ans;
}

char a[300010];

inline long long c2(const long long n) {
    return n * (n + 1) / 2;
}

inline bool valid(int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j < r; j++) {
            int k = j + j - i;
            if (k >= r)
                break;
            if (a[i] == a[j] && a[j] == a[k])
                return true;

        }
    }
    return false;
}

int main() {
    /* vector<int> testv; */
    /* printf("%d\n", dfs(testv)); */
    /* 8 */

    scanf("%s", a);
    long long n = strlen(a);

    long long ans = 0;
    if (n >= 9)
        ans += c2(n-9+1);

    for (int i = 0; i < n; i++) {
        for (int d = 1; d <= 8; d++) {
            int j = i + d;
            if (j > n)
                break;
            if (valid(i, j))
                ans++;
        }
    }

    cout << ans << endl;


    return 0;
}
