#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, a[maxn];
void work() {
  int cnt = 0, odd = 0;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i == 0 || i == n - 1) {
      continue;
    }
    cnt += a[i] >> 1;
    odd += a[i] & 1;
    ans += (a[i] + 1) >> 1;
  }
  if (n == 3 && odd) {
    cout << -1 << endl;
  } else {
    cout << (cnt == 0 && odd ? -1 : ans) << endl;
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
