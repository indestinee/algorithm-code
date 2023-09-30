#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
int n, cnt;

int find(int x) {
  if (cnt == 0 || x > a[cnt]) {
    return -1;
  }

  int l = 1, r = cnt;
  while (l < r) {
    int m = (l + r) >> 1;
    if (a[m] > x) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {

    scanf("%d", &n);
    cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      int pos = find(x);

      if (pos == -1) {
        a[++cnt] = x;
      } else {
        a[pos] = a[cnt];
        cnt = pos;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
