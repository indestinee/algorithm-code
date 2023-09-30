#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, m, c[maxn];
long long cnt[maxn], sum[maxn];
int main() {

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &c[i * m + j]);
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int color = c[i * m + j];
      ans += cnt[color] * i - sum[color];
      cnt[color]++;
      sum[color] += i;
    }
  }

  memset(cnt, 0, sizeof cnt);
  memset(sum, 0, sizeof sum);

  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      int color = c[i * m + j];
      ans += cnt[color] * j - sum[color];
      cnt[color]++;
      sum[color] += j;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
