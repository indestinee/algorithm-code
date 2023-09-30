#include <bits/stdc++.h>
using namespace std;

void work() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf("%d", i);
    for (int j = n; j >= 1; j--) {
      if (i == j) {
        continue;
      }
      printf(" %d", j);
    }
    puts("");
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
