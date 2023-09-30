#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int cnt[256];

char a[maxn];
void work() {
  scanf("%s", a);
  memset(cnt, 0, sizeof cnt);
  int n = strlen(a);

  int mini = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (cnt[int(a[i])]++ == 0) {
      mini = min(mini, i);
    }
  }
  printf("%s\n", a + mini);
}

int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {

    work();
  }

  return 0;
}
