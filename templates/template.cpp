#include <bits/stdc++.h>
using namespace std;

const int MAXN_IT = 100000;
class interval_tree {
public:
  long long val[MAXN_IT];
  double lazy[MAXN_IT];

  interval_tree(int maxn = 0) { set_maxn(maxn); }
  ~interval_tree() {}

  inline long long query(const int &a, const int &b) {
    return _query(a, b, 1, m_maxn, 1);
  }

  inline void modify(const int &a, const int &b, const double &value) {
    _update(a, b, value, 1, m_maxn, 1);
  }

  inline void build() { _build(1, 1, m_maxn); }

  inline void set_maxn(int maxn) { m_maxn = maxn; }

private:
  int m_maxn;

  // set lazy zero
  const double lazy_zero = 0;

  inline void _build(const int &rt, const int &l, const int &r) {
    lazy[rt] = lazy_zero;
    if (l == r) {
      // TODO initial value node
      val[rt] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    _build(rt << 1, l, mid);
    _build(rt << 1 | 1, mid + 1, r);
    val[rt] = _merge_value(val[rt << 1], val[rt << 1 | 1]);
  }

  inline long long _merge_value(const long long &a, const long long &b) {
    // TODO merge value nodes
    return a + b;
  }

  inline void _push_up(const int &rt) { ; }

  inline void _push_down_lazy(const double &father, double &son) {
    // TODO push lazy down
    son = son + father;
  }

  inline void _apply_lazy(const double &lazy_node, long long &value_node) {
    // TODO apply lazy to value node
    value_node = value_node + lazy_node;
  }

  inline void _push_down(const int &rt) {
    if (lazy[rt] != lazy_zero) {
      _push_down_lazy(lazy[rt], lazy[rt << 1]);
      _push_down_lazy(lazy[rt], lazy[rt << 1 | 1]);
      _apply_lazy(lazy[rt], val[rt << 1]);
      _apply_lazy(lazy[rt], val[rt << 1 | 1]);
      lazy[rt] = lazy_zero;
    }
  }

  inline void _update(const int &a, const int &b, const double &value,
                      const int &l, const int &r, const int &rt) {
    if (a <= l && r <= b) {
      _push_down_lazy(value, lazy[rt]);
      _apply_lazy(value, val[rt]);
      return;
    }
    _push_down(rt);
    int mid = (l + r) >> 1;
    if (a <= mid) {
      _update(a, mid, value, l, r, rt << 1);
    }
    if (mid < b) {
      _update(mid + 1, b, value, l, r, rt << 1 | 1);
    }
    val[rt] = _merge_value(val[rt << 1], val[rt << 1 | 1]);
  }

  inline long long _query(const int &a, const int &b, const int &l,
                          const int &r, const int &rt) {
    if (a <= l && b >= r)
      return val[rt];

    int mid = (l + r) >> 1;
    // TODO update initial value
    long long ret(0);
    if (a <= mid) {
      ret = _merge_value(ret, _query(a, b, l, mid, rt << 1));
    }
    if (mid < b) {
      ret = _merge_value(ret, _query(a, b, mid + 1, r, rt << 1 | 1));
    }
    return ret;
  }
};
interval_tree tree;

int main() {
  int cas;
  scanf("%d", &cas);
  for (int cas_i = 1; cas_i <= cas; cas_i++) {

    printf("Case #%d: \n", cas_i);
  }
}
