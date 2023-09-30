/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/17
 *  file name:
 *      a.cpp
 */

#include <bits/stdc++.h>
using namespace std;

long long x, y, z;
int main() {
    cin >> x >> y >> z;
    cout << (x+y)/z << " " << ((x%z+y%z>=z)?z-max(x%z, y%z):0) << endl;

    return 0;
}
