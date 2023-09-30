#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;

char a[maxn];
long long n;
long long work() {
  scanf("%lld%s", &n, a);
  int len = strlen(a);
  long long x = 1, y = 1;
  for (int i = 0; i < len; i++) {
    if (a[i] == 'R') {
      y += 1;
    } else {
      x += 1;
    }
  }

  if (x == 1 || y == 1) {
    return n;
  }

  long long mx = n, my = n, ans = (n - x + 1) * (n - y + 1);

  for (int i = len - 1; i >= 0; i--) {
    if (a[i] == 'R') {
      y--;
      my--;
      ans += (x > 1) ? (mx - x + 1) : 1;
    } else {
      x--;
      mx--;
      ans += (y > 1) ? (my - y + 1) : 1;
    }
  }
  return ans;
}
int main() {

  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    printf("%lld\n", work());
  }

  return 0;
}
