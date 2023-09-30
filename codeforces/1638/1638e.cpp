#include <bits/stdc++.h>
using namespace std;

template <typename T> class FenwickTree {
private:
  vector<T> v;
  inline int lowbit(const int &x) { return -x & x; }
  inline T update(const T &a, const T &b) {
    // to update
    return a + b;
  }

public:
  void init(const int &size, const T &value) {
    v.resize(size + 10);
    fill(v.begin(), v.end(), value);
  }
  inline void modify(int x, const T &value) {
    while (x) {
      v[x] = update(v[x], value);
      x -= lowbit(x);
    }
  }
  inline T query(int x) {
    T res = 0;
    while (x < int(v.size())) {
      res = update(res, v[x]);
      x += lowbit(x);
    }
    return res;
  }
};

const int maxn = 1e6 + 10;
FenwickTree<long long> fenwick_tree;
int n, q;
char order[10];
long long color[maxn];
map<pair<int, int>, int> interval_to_color_map, tmp;

void work_on_interval(int l, int r, int prev, int cur) {
  if (prev == cur) {
    return;
  }
  long long delta = color[prev] - color[cur];
  fenwick_tree.modify(l - 1, -delta);
  fenwick_tree.modify(r, delta);
}

void color_op() {
  int l, r, c;
  scanf("%d%d%d", &l, &r, &c);

  map<pair<int, int>, int>::iterator st =
      interval_to_color_map.lower_bound({l + 1, 0});
  st--;

  tmp.clear();
  while (st != interval_to_color_map.end()) {
    int al = st->first.first, ar = st->first.second, ac = st->second;

    if (al > r) {
      break;
    }

    if (al < l) {
      tmp[{al, l - 1}] = ac;
    }
    if (ar > r) {
      tmp[{r + 1, ar}] = ac;
    }

    work_on_interval(max(al, l), min(ar, r), ac, c);
    interval_to_color_map.erase(st++);
  }
  interval_to_color_map.insert(tmp.begin(), tmp.end());
  interval_to_color_map[{l, r}] = c;
}

void add_op() {
  int c, x;
  scanf("%d%d", &c, &x);
  color[c] += x;
}

void query_op() {
  int x;
  scanf("%d", &x);
  auto st = interval_to_color_map.lower_bound({x + 1, 0});
  st--;
  printf("%lld\n", fenwick_tree.query(x) + color[st->second]);
}

int main() {
  scanf("%d%d", &n, &q);
  interval_to_color_map[{0, 0}] = 0;
  interval_to_color_map[{1, n}] = 1;
  interval_to_color_map[{n + 1, n + 1}] = 0;
  fenwick_tree.init(n, 0);
  while (q--) {
    scanf("%s", order);
    switch (order[0]) {
    case 'C':
      color_op();
      break;
    case 'A':
      add_op();
      break;
    case 'Q':
      query_op();
      break;
    }
  }
  return 0;
}
