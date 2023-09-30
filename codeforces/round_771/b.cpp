#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, a[maxn];

bool work() {
  int max_odd = -1, max_even = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1) {
      if (a[i] < max_odd) {
        return false;
      }
      max_odd = a[i];
    } else {
      if (a[i] < max_even) {
        return false;
      }
      max_even = a[i];
    }
  }
  return true;
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    puts(work() ? "Yes" : "No");
  }

  return 0;
}
