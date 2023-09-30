#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, a[maxn], b[maxn];
long long dp[2][10010];
void work() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  long long ans = 0;

  for (int i = 0; i < n; i++) {
    ans += a[i] * a[i] + b[i] * b[i];
  }
  ans *= (n - 1);

  int s_all = 0, s_max = 0;

  int cur = 0, bef = 1;
  memset(dp[cur], 0x3f, sizeof dp[cur]);
  dp[cur][0] = ans;

  for (int i = 0; i < n; i++) {
    swap(cur, bef);
    memset(dp[cur], 0x3f, sizeof(long long) * (s_max + 1 + max(a[i], b[i])));

    for (int j = 0; j <= s_max; j++) {
      int k = s_all - j;

      if (dp[bef][j] == 0x3f3f3f3f3f3f3f3f) {
        continue;
      }

      dp[cur][j + a[i]] =
          min(dp[cur][j + a[i]], dp[bef][j] + 2 * a[i] * j + 2 * b[i] * k);
      dp[cur][j + b[i]] =
          min(dp[cur][j + b[i]], dp[bef][j] + 2 * b[i] * j + 2 * a[i] * k);
    }

    s_max += max(a[i], b[i]);
    s_all += a[i] + b[i];
  }

  long long mini = 1e18;
  for (int i = 0; i <= s_max; i++) {
    mini = min(mini, dp[cur][i]);
  }
  cout << mini << endl;
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    work();
  }

  return 0;
}
