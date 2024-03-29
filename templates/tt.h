    ${1:int} gcd($1 x, $1 y) {/*{{{*/
return y?gcd(y, x%y):x;
}/*}}}*/
endsnippet
    snippet lcm
    ${1:int} lcm($1 x, $1 y) {/*{{{*/
return x/gcd(x,y)*y;
}/*}}}*/
endsnippet
    snippet bit
/* @binary indexed tree {{{ */
const int BIT_MAXN = 1000010;
class bit{
 public:
  //  single node edit, prefix query, default sum
  int m_maxn;
  int m_c[BIT_MAXN];
  bit(int maxn=BIT_MAXN-1) {init(maxn);}
  ~bit() {}
  inline void init(int maxn=BIT_MAXN-1) {
    assert(maxn < BIT_MAXN);
    m_maxn = maxn;
    memset(m_c, 0, sizeof(int) * (m_maxn+1));
  }
  inline void update(const int &x, const int &value) {
    for (int i = x; i <= m_maxn; i += lowbit(i)) {
      m_c[i] = m_c[i] + value;
    }
  }
  inline int query(const int &x, int *c) {
    int result = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
      result = result + c[i];
    }
    return result;
  }

 private:
  inline int lowbit(const int &x) {
    return -x & x;
  }
};
/*}}}*/
endsnippet
    snippet bit1
/* @binary indexed tree {{{
 * single point modify, prefix query
 */
inline int lowbit(const int &x) {
  return -x & x;
}
inline void modify(int x, int *c, int d = 1) {
  while (x < maxn) {
    c[x] += d;
    x += lowbit(x);
  }
}
inline int query(int x, int *c) {
  int ret = 0;
  while (x) {
    ret += c[x];
    x -= lowbit(x);
  }
  return ret;
}
/* }}} */
endsnippet
    snippet bit2
/* @binary indexed tree {{{
 * prefix modify, single point query
 */
inline int lowbit(const int &x) {
  return -x & x;
}
inline void modify(int x, int *c, int d = 1) {
  while (x) {
    c[x] += d;
    x -= lowbit(x);
  }
}
inline int query(int x, int *c) {
  int ret = 0;
  while (x < maxn) {
    ret += c[x];
    x += lowbit(x);
  }
  return ret;
}
/* }}} */
endsnippet
    snippet it
/* @interval tree {{{ */
const int IT_MAXN = ${1:1000010};
class interval_tree{
 public:
  ${2:int} val[IT_MAXN];
  $2 lazy[IT_MAXN];

  interval_tree(int maxn=IT_MAXN) {
    set_maxn(maxn);
  }
  ~interval_tree() {}

  inline $2 query(const int &a, const int &b) {
    return _query(a, b, 1, m_maxn, 1);
  }
  inline void modify(const int &a, const int &b, const int &value) {
    _update(a, b, value, 1, m_maxn, 1);
  }

  inline void build() {
    _build(1, 1, m_maxn);
  }
  inline void set_maxn(const int &maxn) {
    m_maxn = maxn;
    assert(m_maxn*4<IT_MAXN);
  }
 private:
  int m_maxn;
  inline void _build(const int &rt, const int &l, const int &r) {
    memset(lazy, 0, sizeof(int)*m_maxn*4);
    if (l == r) {
      val[rt] = arr[l];
      return;
    }
    int mid = (l + r) >> 1;
    _build(rt<<1, l, mid);
    _build(rt<<1|1, mid+1, r);
    _push_up(rt);
  }
  inline void _push_up(const int &rt) {
    val[rt] = ${3:val[rt<<1] + val[rt<<1|1];}
  }
  inline void _push_down(const int &rt) {
    if (lazy[rt]) {
      lazy[rt<<1]   = ${6:lazy[rt<<1] + lazy[rt]};
      lazy[rt<<1|1] = ${7:lazy[rt<<1|1] + lazy[rt]};
      val[rt<<1]    = ${8:val[rt<<1] + lazy[rt]};
      val[rt<<1|1]  = ${9:val[rt<<1|1] + lazy[rt]};
      lazy[rt] = ${10:0};
    }
  }
  inline void _update(const int &a, const int &b, const int &value, const int &l, const int &r, const int &rt) {
    if (a <= l && r <= b) {
      lazy[rt] = ${11:lazy[rt] + value;}
      val[rt]  = ${12:val[rt] + value;}
      return;
    }
    _push_down(rt);
    int mid = (l + r) >> 1;
    if (a <= mid)
      _update(a, mid, value, l, r, rt<<1);
    if (mid < b)
      _update(mid+1, b, value, l, r, rt<<1|1);
    _push_up(rt);
  }


  inline $2 _query(const int &a, const int &b, const int &l, const int &r, const int &rt) {
    if (a <= l && b >= r)
      return val[rt];

    int mid = (l + r) >> 1;
    $2 ret = 0;
    if (a <= mid)
      ret = ${4:ret + _query(a, b, l, mid, rt<<1);}
    if (mid < b)
      ret = ${5:ret + _query(a, b, mid+1, r, rt<<1|1);}
    return ret;
  }
};
interval_tree tree;
/*}}}*/
endsnippet
    snippet qp
/* @quick pow: x**b {{{ */
inline ${1:long long} quick_pow($1 x, ${2:long long} b) {
$1 res(1);
while (b) {
if (b & 1)
res = res * x${3};
x = x * x$3;
b >>= 1;
}
return res;
}
/*}}}*/
endsnippet
    snippet point
/* @point {{{ */
class point{
 public:
  ${1:int} x, y;
  point(const $1 &x=0, const $1 &y=0): x(x), y(y) {}
  friend inline point operator + (const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend inline point operator - (const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend inline point operator * (const point &a, const $1 &b) {
    return point(a.x * b, a.y * b);
  }
  friend inline point operator * (const $1 &b, const point &a) {
    return point(a.x * b, a.y * b);
  }
  friend inline point operator / (const point &a, const $1 &b) {
    return point(a.x / b, a.y / b);
  }
  friend inline $1 dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
  }
  friend inline $1 det(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
  }
  ~point() {}
};
/*}}}*/
endsnippet
    snippet manacher
/* @manacher {{{ */
template<typename T>
void manacher(const T* arr, const int n, int *len) {
  len[0] = 1;
  for (int i = 1, j = 0; i < (n<<1)-1; i++) {
    int p = i >> 1, q = i - p, r = ((j+1) >> 1) + len[j] - 1;
    len[i] = r < q ? 0 : min(r - q + 1, len[(j<<1)-i]);
    while (p - len[i] >= 0 && q + len[i] < n &&
        arr[p-len[i]] == arr[q+len[i]])
      len[i]++;
    if (q + len[i] - 1 > r)
      j = i;
  }
}
/* }}} */
endsnippet
    snippet euler
/* @euler sieve, finding all primes in range [2, maxn) {{{ */
const int prime_maxn = 1e4 + 10;
int prime[prime_maxn], prime_cnt = 0;
bool prime_vis[prime_maxn];
void euler() {
  for (int i = 2; i < prime_maxn; i++) {
    if (!prime_vis[i])
      prime[prime_cnt++] = i;
    for (int j = 0; j < prime_cnt && i*prime[j] < prime_maxn; j++) {
      prime_vis[i*prime[j]]  = true;
      if (i % prime[j] == 0)
        break;
    }
  }
}
/* }}} */
endsnippet
    snippet ms

/* @monotone stack {{{ */
/* compare function same with priority_queue, use <= or >= instead of < > */
const int q_maxn = 1010;
template<typename T, class _compare=less<T>>
class monotone_stack{
 private:
  int r;
  pair<T, int> q[q_maxn];
  _compare __comp;
 public:
  monotone_stack() {clear();}
  inline void clear() {r = -1;}
  inline bool empty() {return r<0;}
  inline bool size() {return r+1;}
  inline int push(T val, int time_stamp, int empty_return = -1) {
    while (0 <= r && __comp(val, q[r].first))
      --r;
    int res = (r < 0) ? empty_return: q[r].second;
    q[++r] = make_pair(val, time_stamp);
    return res;
  }
};
struct cmp_small{
  bool operator () (const int &a, const int &b) {
    return a <= b;
  }
};

monotone_stack<int, cmp_small> s;
/* }}} */

endsnippet

    snippet mq

/* @monotone queue {{{ */
/* compare function same with priority_queue, use <= or >= instead of < > */
const int q_maxn = 1010;
template<typename T, class _compare=less<T>>
class monotone_queue{
 private:
  int l, r;
  pair<T, int> q[q_maxn];
  _compare __comp;
 public:
  monotone_queue() {clear();}
  inline void clear() {l = 0, r = -1;}
  inline bool empty() {return r<l;}
  inline int size() {return r-l+1;}
  inline void push(T val, int time_stamp) {
    while (l <= r && __comp(val, q[r].first))
      --r;
    q[++r] = make_pair(val, time_stamp);
  }
  inline T top(int time_stamp, T empty_return=T(-1)) {
    while (l <= r && q[l].second < time_stamp)
      ++l;
    int res = (l > r) ? empty_return : q[l].first;
    return res;
  }
};

struct cmp_large{
  bool operator () (const int &a, const int &b) {
    return a >= b;
  }
};
monotone_queue<int, cmp_large> q_large;
/* }}} */
endsnippet
    snippet frac
class fraction{/* @fraction {{{ */
 private:
  inline friend fraction raw_mul(const fraction &a, const fraction &b) {
    return fraction(a.n * b.n, a.d * b.d, false);
  }
  fraction($1 _n, $1 _d, bool simplify) {
    if (_d < 0)
      _d = -_d, _n = -_n;
    if (simplify) {
      $1 g = abs(gcd(_n, _d));
      _n /= g, _d /= g;
    }
    n = _n, d = _d;
  }
 public:
  ${1:long long} n, d;
  fraction($1 _n=0, $1 _d=1) {
    if (_d < 0)
      _d = -_d, _n = -_n;
    $1 g = abs(gcd(_n, _d));
    _n /= g, _d /= g;
    n = _n, d = _d;
  }
  inline friend fraction operator + (const fraction &a, const fraction &b) {
    $1 g = gcd(a.d, b.d);
    return fraction(b.d / g * a.n + a.d / g * b.n, a.d / g * b.d, false);
  }
  inline friend fraction operator - (const fraction &a, const fraction &b) {
    $1 g = gcd(a.d, b.d);
    return fraction(b.d / g * a.n - a.d / g * b.n, a.d / g * b.d, false);
  }
  inline friend fraction operator * (fraction a, fraction b) {
    return raw_mul(fraction(a.n, b.d), fraction(b.n, a.d));
  }
  inline friend fraction operator / (fraction a, fraction b) {
    return raw_mul(fraction(a.n, b.n), fraction(b.d, a.d));
  }
  inline friend bool operator < (fraction a, fraction b) {
    return a.n * b.d < b.n * a.d;
  }
  inline friend bool operator > (fraction a, fraction b) {
    return a.n * b.d > b.n * a.d;
  }
  inline friend bool operator == (fraction a, fraction b) {
    return a.n * b.d == b.n * a.d;
  }
  inline fraction& operator = (fraction a) {
    n = a.n, d = a.d;
    return *this;
  }
  friend ostream& operator << (ostream& out, const fraction &a) {
    out << "[" << a.n << "/" << a.d << "]";
    return out;
  }
};/*}}}*/
endsnippet
    snippet bra
class best_rational_approximations{/*{{{*/
 private:
  vector<${1:long long}> v[2];
  inline void transform(fraction x, vector<$1> &v) {
    v.clear();
    while (x.d != 0) {
      v.push_back(x.n / x.d);
      x = fraction(x.d, x.n % x.d);
    }
  }
 public:
  inline fraction run(fraction mini, fraction maxi, int inclusive=0) {
    /*
     *  inclusive:
     *      0: (mini, maxi)
     *      1: [mini, maxi)
     *      2: (mini, maxi]
     *      3: [mini, maxi]
     */
    transform(mini, v[0]);
    transform(maxi, v[1]);
    $1 h1 = 1, h2 = 0, k1 = 0, k2 = 1;

    if ((inclusive & 1) == 0) {
      if (v[0].size() & 1) {
        v[0].push_back(inf);
      } else {
        --(*v[0].rbegin());
        v[0].push_back(1);
        v[0].push_back(inf);
      }
    }

    if ((inclusive & 2) == 0) {
      if (v[1].size() & 1) {
        --(*v[1].rbegin());
        v[1].push_back(1);
        v[1].push_back(inf);
      } else {
        v[1].push_back(inf);
      }
    }

    int i;
    for (i = 0; v[0][i] == v[1][i]; i++) {
      h2 = v[0][i] * h1 + h2;
      k2 = v[0][i] * k1 + k2;
      swap(k1, k2);
      swap(h1, h2);
    }

    int x = int(i+1 != int(v[i&1].size()));

    h2 = (min(v[0][i], v[1][i])+x) * h1 + h2;
    k2 = (min(v[0][i], v[1][i])+x) * k1 + k2;
    return fraction(h2, k2);
  }
};/*}}}*/
endsnippet
    snippet dis
template<typename T>
inline void discretization(vector<T> &v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}
template<typename T>
inline void discretization(T *v, int &n) {
  sort(v, v + n);
  n = unique(v, v + n) - v;
}
endsnippet

    snippet fft
const double PI = acos(-1.0);

int to_complex(int* const a, int n, complex<double> *res, int m) {
  for (int i = 0; i < n; i++)
    res[i] = complex<double>(a[i], 0);
  for (int i = n; i < m; i++)
    res[i] = complex<double>(0, 0);
  return m;
}

void FFT(complex<double>* const a, const int n, int forward) {
  for (int i = 1, j = n/2, k = n/2; i < n-1; i++) {
    if (i < j)
      swap(a[i], a[j]);
    for (k = n / 2; j & k; k >>= 1)
      j ^= k;
    j ^= k;
  }
  for (int len = 2; len <= n; len <<= 1) {
    double alpha = 2 * PI / len * forward;
    complex<double> wlen(cos(alpha), sin(alpha));
    for (int i = 0; i < n; i += len) {
      complex<double> w(1, 0);
      for (int k = i; k < i + len/2; k++) {
        complex<double> u = a[k];
        complex<double> v = w * a[k+len/2];
        a[k] = u + v;
        a[k+len/2] = u - v;
        w *= wlen;
      }
    }
  }
  if (forward == -1)
    for (int i = 0; i < n; i++)
      a[i] /= n;
}

endsnippet

    snippet ntt
    vector<long long> factorize(long long n) {
  vector<long long> factors;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i)
      continue;
    factors.push_back(i);
    if (i * i != n)
      factors.push_back(n/i);
  }
  return factors;

}
inline long long quick_pow(long long x, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1)
      res = res * x % mod;
    x = x * x % mod;
    b >>= 1;
  }
  return res;
}
long long find_g(long long mod) {
  vector<long long> factors = factorize(mod-1);
  for (long long i = 2; i < mod; i++) {
    bool is_g = true;
    for (auto factor: factors) {
      if (quick_pow(i, factor, mod) == 1) {
        is_g = false;
        break;
      }
    }
    if (is_g)
      return i;
  }
  return -1;
}
void NTT(long long *a, int n, long long g, int forward) {
  for (int i = 1, j = n/2, k = n/2; i < n-1; i++) {
    if (i < j)
      swap(a[i], a[j]);
    for (k = n / 2; j & k; k >>= 1)
      j ^= k;
    j ^= k;
  }
  for (int len = 2; len <= n; len <<= 1) {
    long long wlen = quick_pow(g, (mod-1)/len, mod);
    for (int i = 0; i < n; i += len) {
      long long w = 1;
      for (int k = i; k < i + len/2; k++) {
        long long u = a[k], v = w * a[k+len/2] % mod;
        a[k] = (u + v) % mod;
        a[k+len/2] = (u - v + mod) % mod;
        w = w * wlen % mod;
      }
    }
  }
  if (forward == -1) {
    reverse(a + 1, a + n);
    long long inv_n = quick_pow(n, mod-2, mod);
    for (int i = 0; i < n; i++)
      a[i] = (a[i] * inv_n) % mod;
  }
}
endsnippet

    snippet itt

/* @interval tree {{{ */
const int IT_MAXN = maxn << 2;
class interval_tree{
 public:
  inline void set_maxn(const int mmaxn) {
    m_maxn = mmaxn;
    assert((m_maxn<<2) < IT_MAXN);
  }
  inline void build() {
    _build(1, 1, m_maxn);
  }
  inline $1 query(const int a, const int b) {
    return _query(a, b, 1, m_maxn, 1);
  }
  inline void modify(const int a, const int b, $2 val) {
    _update(a, min(b, m_maxn), lazy, 1, m_maxn, 1);
  }
 private:
  int m_maxn;
  ${1:NODE} node[IT_MAXN], eye = ${3:/* TODO */};
  ${2:LAZY} lazy[IT_MAXN], lazy_init = ${4:/* TODO */};

  inline $2 lazy2lazy($2 father, $2 son) {
    ${5:/* TODO */}
  }
  inline $1 lazy2node($2 father, $1 son) {
    ${6:/* TODO */}
  }
  inline $1 combine($1 a, $1 b) {
    ${7:/* TODO */}
  }
  inline $1 init_node(int idx) {
    ${8:/* TODO */}
  }

  void _build(const int rt, const int l, const int r) {
    if (l == r) {
      node[rt] = init_node(l);
      lazy[rt] = lazy_init;
      return;
    }
    int mid = (l + r) >> 1;
    _build(rt<<1, l, mid);
    _build(rt<<1|1, mid+1, r);
    _push_up(rt);
  }
  inline void _push_up(const int &rt) {
    node[rt] = combine(node[rt<<1], node[rt<<1|1]);
  }
  inline void _push_down(const int &rt) {
    if (lazy[rt] == lazy_init)
      return;
    lazy[rt<<1]   = lazy2lazy(lazy[rt], lazy[rt<<1]);
    lazy[rt<<1|1] = lazy2lazy(lazy[rt], lazy[rt<<1|1]);
    node[rt<<1]   = lazy2node(lazy[rt], node[rt<<1]);
    node[rt<<1|1] = lazy2node(lazy[rt], node[rt<<1|1]);
    lazy[rt] = lazy_init;
  }
  void _update(int a, int b, $2 val, int l, int r, int rt) {
    if (a <= l && r <= b) {
      lazy[rt] = lazy2lazy(val, lazy[rt]);
      node[rt] = lazy2node(val, node[rt]);
      return;
    }
    _push_down(rt);
    int mid = (l + r) >> 1;
    if (a <= mid)
      _update(a, b, val, l, mid, rt<<1);
    if (mid < b)
      _update(a, b, val, mid+1, r, rt<<1|1);
    _push_up(rt);
  }
  $1 _query(int a, int b, int l, int r, int rt) {
    if (a <= l && b >= r)
      return node[rt];
    _push_down(rt);
    $1 ret = eye;
    int mid = (l + r) >> 1;
    if (a <= mid)
      ret = combine(ret, _query(a, b, l, mid, rt<<1));
    if (mid < b)
      ret = combine(ret, _query(a, b, mid+1, r, rt<<1|1));
    _push_up(rt);
    return ret;
  }
};
interval_tree tree;
/*}}}*/
endsnippet
