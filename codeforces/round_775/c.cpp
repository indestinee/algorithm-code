#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;
const int maxn = 2e5 + 10;

int n, m, s[maxn], t[maxn], cnt[maxn], sum[maxn];
long long f[maxn], invf[maxn];

template <typename T> class FenwickTree {
private:
  vector<T> v;
  inline int lowbit(const int &x) { return -x & x; }
  inline T update(const T &a, const T &b) { return a + b; }

public:
  void init(const int &size, const T &value) {
    v.resize(size + 10);
    fill(v.begin(), v.end(), value);
  }
  inline void modify(int x, const T &value) {
    while (x < int(v.size())) {
      v[x] = update(v[x], value);
      x += lowbit(x);
    }
  }
  inline T query(int x) {
    T res = 0;
    while (x > 0) {
      res = update(res, v[x]);
      x -= lowbit(x);
    }
    return res;
  }
};

inline long long quick_pow(long long x, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    b >>= 1;
  }
  return res;
}

inline long long inv(long long x) { return quick_pow(x, mod - 2); }

FenwickTree<int> tree = FenwickTree<int>();

int main() {
  // init
  f[0] = invf[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = f[i - 1] * i % mod;
    invf[i] = invf[i - 1] * inv(i) % mod;
  }
  tree.init(maxn, 0);

  // pre
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    cnt[s[i]]++;
  }
  for (int i = 1; i < maxn; i++) {
    sum[i] = sum[i - 1] + cnt[i];
  }

  for (int i = 1; i <= m; i++) {
    scanf("%d", &t[i]);
  }

  // main
  long long pi_a = 1;
  for (int i = 1; i < maxn; i++) {
    pi_a = pi_a * f[cnt[i]] % mod;
  }

  long long ans = 0;
  for (int i = 1; i <= min(n, m); i++) {
    int cur = t[i];
    // find how many < cur

    long long s = sum[cur - 1] - tree.query(cur - 1);
    long long tmp_ans = f[n - i] * inv(pi_a) % mod * s % mod;

    ans = (tmp_ans + ans) % mod;

    // find how many == cur
    s = sum[cur] - tree.query(cur) - s;
    if (s == 0) {
      break;
    }

    tree.modify(cur, 1);
    pi_a = pi_a * inv(f[s]) % mod * f[s - 1] % mod;

    if (i == n && n < m) {
      ans = (ans + 1) % mod;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
