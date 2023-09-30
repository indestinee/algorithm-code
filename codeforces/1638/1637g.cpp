#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int cnt[maxn];

void work() {
  int n, sum = 1;
  scanf("%d", &n);
  while (sum < n) {
    sum <<= 1;
  }

  while (!q.empty()) {
    q.pop();
  }

  for (int i = 1; i <= n; i++) {
    q.push(i);
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
