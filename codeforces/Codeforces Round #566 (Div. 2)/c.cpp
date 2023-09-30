/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/12
 *  file name:
 *      c.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxc = 1e6 + 10;
int n;
char s[maxc];
vector<string> vs;

vector<int> v[6];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int last = -1, cnt = 0;
        for (char *c = s; *c; c++) {
            cnt++;
            switch (*c) {
                case 'a':
                    last = 0;
                    break;
                case 'e':
                    last = 1;
                    break;
                case 'i':
                    last = 2;
                    break;
                case 'o':
                    last = 3;
                    break;
                case 'u':
                    last = 4;
                    break;
                default:
                    cnt--;
                    break;
            }
        }
        if (last == -1)
            continue;
        v[last].push_back(cnt);
    }
    for (int i = 0; i < 6; i++)
        sort(v[i].begin(), v[i].end());


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j + 1 < int(v[i].size()); j++) {
            if (v[i][j] == v[i][j+1]) {

            }
        }
    }




    return 0;
}
