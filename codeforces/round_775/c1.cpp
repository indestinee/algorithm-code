#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, m;
int s[maxn], t[maxn];

bool good() {
  s[n] = -1;
  t[m] = -1;
  for (int i = 0; i <= min(n, m); i++) {
    if (s[i] < t[i]) {
      return true;
    }
    if (s[i] > t[i]) {
      return false;
    }
  }
  return false;
}
bool finished() {
  for (int i = 1; i < n; i++) {
    if (s[i - 1] > s[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> t[j];
  }
  sort(s, s + n);

  int ans = 0;
  do {
    if (good()) {
      ans += 1;
    } else {
      break;
    }
    next_permutation(s, s + n);
  } while (!finished());

  cout << ans << endl;
  return 0;
}
