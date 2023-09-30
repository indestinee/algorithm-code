#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int n, a[maxn];
int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }

    int st = -1, ed = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) {
        st = i;
        break;
      }
    }

    if (st != -1) {
      for (int j = st + 1; j <= n; j++) {
        if (a[j] == st) {
          ed = j;
        }
      }
    }

    if (st != -1) {
      reverse(a + st, a + ed + 1);
    }
    for (int i = 1; i <= n; i++) {
      printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
  }

  return 0;
}
