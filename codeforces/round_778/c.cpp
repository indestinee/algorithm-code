#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

int n;
long long a[maxn];

priority_queue<long long> q;

bool is_ok() {
  for (int cur = 0; cur < n; cur++) {
    bool find = false;

    while (!q.empty()) {
      long long x = q.top();
      q.pop();

      if (x == a[cur]) {
        find = true;
        break;
      } else if (x < a[cur]) {
        return false;
      } else {
        q.push(x >> 1);
        q.push(x - (x >> 1));
      }
    }

    if (!find) {
      return false;
    }
  }
  return true;
}

void work() {
  while (!q.empty()) {
    q.pop();
  }

  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  q.push(sum);

  sort(a, a + n);
  reverse(a, a + n);

  puts(is_ok() ? "YES" : "NO");
}

int main() {

  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    work();
  }

  return 0;
}
