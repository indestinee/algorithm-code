#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, a[maxn];

int work() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n);
  return a[n - 2] + a[n - 1];
}

int main() {
  int cas;

  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {

    printf("%d\n", work());
  }
  return 0;
}
