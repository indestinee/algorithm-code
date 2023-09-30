#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
const int maxn = 2e5 + 10;

int prime[maxn], prime_cnt;
bool prime_vis[maxn];
void euler() {
  for (int i = 2; i < maxn; i++) {
    if (!prime_vis[i])
      prime[prime_cnt++] = i;
    for (int j = 0; j < prime_cnt && i * prime[j] < maxn; j++) {
      prime_vis[i * prime[j]] = true;
      if (i % prime[j] == 0)
        break;
    }
  }
}

inline long long quick_pow(long long x, long long b) {
  long long res(1);
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

struct node {
  int dst, x, y;
  node(int dst, int x, int y) : dst(dst), x(x), y(y) {}
};

vector<node> v[maxn];
int n, a, b, x, y;

unordered_map<int, int> fenzi, fenmu, final_fenmu;

inline void update_result(int p, int cnt, unordered_map<int, int> &add,
                          unordered_map<int, int> &del, bool update) {

  if (del[p] >= cnt) {
    del[p] -= cnt;
  } else {
    cnt -= del[p];
    del[p] = 0;
    add[p] += cnt;

    if (update) {
      final_fenmu[p] = max(final_fenmu[p], add[p]);
    }
  }
}

inline void ops(int val, unordered_map<int, int> &add,
                unordered_map<int, int> &del, bool update) {
  for (int i = 0; i < prime_cnt && prime[i] * prime[i] <= val; i++) {
    int cnt = 0;
    while (val % prime[i] == 0) {
      val /= prime[i];
      cnt++;
    }
    update_result(prime[i], cnt, add, del, update);
  }
  if (val != 1) {
    update_result(val, 1, add, del, update);
  }
}

void ops(int fenz, int fenm, bool update) {
  ops(fenz, fenzi, fenmu, false);
  ops(fenm, fenmu, fenzi, update);
}

long long ans = 0;

void dfs(int cur, int fa = -1, long long val = 1) {
  /* cout << cur << " " << fa << " : " << val << endl; */
  ans = (ans + val) % mod;
  for (node nxt : v[cur]) {
    if (nxt.dst == fa) {
      continue;
    }

    ops(nxt.y, nxt.x, true);

    dfs(nxt.dst, cur, val * nxt.y % mod * inv(nxt.x) % mod);

    ops(nxt.x, nxt.y, false);
  }
}

long long work() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d%d", &a, &b, &x, &y);
    v[a].push_back(node(b, x, y));
    v[b].push_back(node(a, y, x));
  }
  ans = 0;

  dfs(1);

  for (auto i : final_fenmu) {
    ans = ans * quick_pow(i.first, i.second) % mod;
    /* cout << "~" << i.first << " " << i.second << endl; */
  }

  fenzi.clear();
  fenmu.clear();
  final_fenmu.clear();

  for (int i = 1; i <= n; i++) {
    v[i].clear();
  }
  return ans;
}

int main() {

  euler();

  int cas;
  scanf("%d", &cas);
  for (int _ = 1; _ <= cas; _++) {
    printf("%lld\n", work());
  }
  return 0;
}
