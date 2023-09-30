/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/12
 *  file name:
 *      a.cpp
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> s;

int main() {
    long long n;
    cin >> n;
    if (n & 1) {
        cout << 0 << endl;
    } else {
        cout << (1LL << (n >> 1)) << endl;
    }


    return 0;
}
