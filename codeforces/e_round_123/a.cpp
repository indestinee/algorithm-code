#include <bits/stdc++.h>
using namespace std;

int n, ok[3];
char a[1000];
bool work() {
  for (char *c = a; *c; c++) {
    switch (*c) {
    case 'r':
      ok[0] = 1;
      break;
    case 'g':
      ok[1] = 1;
      break;
    case 'b':
      ok[2] = 1;
      break;
    case 'R':
      if (!ok[0]) {
        return false;
      }
      break;
    case 'G':
      if (!ok[1]) {
        return false;
      }
      break;
    case 'B':
      if (!ok[2]) {
        return false;
      }
      break;
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", a);
    ok[0] = ok[1] = ok[2] = 0;
    puts(work() ? "YES" : "NO");
  }
  return 0;
}
