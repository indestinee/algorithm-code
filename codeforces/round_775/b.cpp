#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, c, a[maxn];
bool vis[maxn];

int find(int l, int r, int val) {
  if (a[r] < val) {
    return -1;
  }

  while (l < r) {
    int m = (l + r) >> 1;
    if (a[m] >= val) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

bool work() {
  sort(a, a + n);
  int m = unique(a, a + n) - a;
  if (a[0] != 1) {
    return false;
  }

  n = m;

  for (int i = 0; i < n; i++) {
    // a[i] -> [k*a[i], (k+1)*a[i])

    int cur = i + 1;
    while (cur != -1 && cur < n) {
      int k = a[cur] / a[i];

      if (!vis[k]) {
        return false;
      }

      int val = (k + 1) * a[i];
      // find first index >= val

      cur = find(cur + 1, n - 1, val);
    }
  }

  return true;
}

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      vis[a[i]] = true;
    }
    puts(work() ? "Yes" : "No");
    for (int i = 0; i < n; i++) {
      vis[a[i]] = false;
    }
  }
  return 0;
}
