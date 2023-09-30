#include <bits/stdc++.h>
using namespace std;
int n, a[110];

set<int> s;

void work() {
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ans += (i + 1) * (n - i) * (1 + int(a[i] == 0));
  }
  cout << ans << endl;
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    work();
  }

  return 0;
}
