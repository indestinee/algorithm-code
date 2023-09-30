/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/17
 *  file name:
 *      test.cpp
 */

#include <bits/stdc++.h>
using namespace std;

multiset<int> s;
int main() {
    s.insert(1);
    s.insert(1);
    cout << s.size() << endl;
    s.erase(1);
    cout << s.size() << endl;


    return 0;
}
