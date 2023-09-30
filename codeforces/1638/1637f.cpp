#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, a[maxn], deg[maxn];
vector<int> v[maxn];

pair<long long, long long> dfs(const int cur, const int father = -1) {
  long long ans = 0, maxi = 0, maxi2 = 0;
  for (auto u : v[cur]) {
    if (u == father) {
      continue;
    }
    pair<long long, long long> value = dfs(u, cur);

    if (value.second > maxi2) {
      maxi2 = value.second;
    }
    if (maxi2 > maxi) {
      swap(maxi2, maxi);
    }
    ans += value.first;
  }

  cout << ans << " " << a[cur] << " " << maxi << " " << maxi2 << endl;

  if (maxi < a[cur]) {
    ans += a[cur] - maxi;
    maxi = a[cur];
  }

  if (father == -1 && maxi2 < a[cur]) {
    ans += a[cur] - maxi2;
  }

  return {ans, maxi};
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);

    deg[x]++;
    deg[y]++;
  }

  int max_index = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[max_index]) {
      max_index = i;
    }
  }

  printf("%lld\n", dfs(max_index).first);

  return 0;
}
