#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, a[maxn];

const int th = 100, ith = 100000 / th + 1;

map<int, int> mp;

int work() {
  int maxi = 0;
  for (int d = -th; d <= th; d++) {
    mp.clear();
    for (int i = 0; i < n; i++) {
      int s = a[i] - d * i;
      maxi = max(maxi, ++mp[s]);
    }
  }
  return n - maxi;
}

map<long long, int> mp2;

inline int add(int i, int j) {
  int d = (a[j] - a[i]) / (j - i);
  if (d * (j - i) + a[i] != a[j] || (d >= -th && d <= th)) {
    return 0;
  }

  long long s = a[j] - d * j;
  return ++mp2[s << 32 | d];
}

int work2() {
  // a[i] = s + d * i, d >= 1000
  // a[j] - a[i] = d * (j - i)
  // j - i <= 100
  int maxi = 0;

  for (int j = 0; j < n; j++) {
    for (int i = max(0, j - ith); i < j; i++) {
      maxi = max(maxi, add(i, j));
    }
    mp2.clear();
  }

  return n - maxi - 1;
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  int ans = n;
  ans = min(ans, work());
  ans = min(ans, work2());
  printf("%d\n", ans);
  return 0;
}
