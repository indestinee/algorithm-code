#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
const int maxn = 2e5 + 10;

int n, m, q, x[maxn], y[maxn], cntx, cnty;
bool visx[maxn], visy[maxn];
long long k;

long long quick_pow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

long long work() {
  scanf("%d%d%lld%d", &n, &m, &k, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }

  cntx = cnty = 0;
  memset(visx, 0, sizeof(bool) * (n + 1));
  memset(visy, 0, sizeof(bool) * (m + 1));

  long long res = 0;
  for (int i = q; i >= 1; i--) {
    if (cntx == n || cnty == m) {
      break;
    }

    if (visx[x[i]] && visy[y[i]]) {
      continue;
    }

    res += 1;
    if (!visx[x[i]]) {
      visx[x[i]] = true;
      cntx++;
    }

    if (!visy[y[i]]) {
      visy[y[i]] = true;
      cnty++;
    }
  }
  return quick_pow(k, res);
}

int main() {

  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    printf("%lld\n", work());
  }

  return 0;
}
