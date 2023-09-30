#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int n, a[maxn], mini[maxn];
/* @point {{{ */
class point {
public:
  int x, y;
  point(const int &x = 0, const int &y = 0) : x(x), y(y) {}
  friend inline point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend inline point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend inline point operator*(const point &a, const int &b) {
    return point(a.x * b, a.y * b);
  }
  friend inline point operator*(const int &b, const point &a) {
    return point(a.x * b, a.y * b);
  }
  friend inline point operator/(const point &a, const int &b) {
    return point(a.x / b, a.y / b);
  }
  friend inline int dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
  }
  friend inline int det(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
  }
  ~point() {}
};
/*}}}*/

int main() {
  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        ans = false;
      }
    }
    cout << (ans ? "NO" : "YES") << endl;
  }
  return 0;
}
