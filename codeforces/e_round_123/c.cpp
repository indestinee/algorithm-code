#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4;

int n, m, a[maxn];
long long ans[maxn];

long long calc(int k) {
  long long s = 0, res = 0;
  for (int i = 1; i < k; i++) {
    s += a[i];
  }

  long long ks = 0, mini = 0;
  for (int i = k; i <= n; i++) {
    s += a[i];
    ks += a[i - k];
    mini = min(mini, ks);

    res = max(res, s - mini + k * m);
  }
  return res;
}

void work() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i <= n; i++) {
    ans[i] = calc(i);
    if (i > 0) {
      ans[i] = max(ans[i], ans[i - 1]);
    }
    printf("%lld%c", ans[i], (i == n) ? '\n' : ' ');
  }
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    work();
  }

  return 0;
}
