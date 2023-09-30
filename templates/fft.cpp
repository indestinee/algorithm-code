#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int to_complex(int *const a, int n, complex<double> *res, int m) {
  for (int i = 0; i < n; i++)
    res[i] = complex<double>(a[i], 0);
  for (int i = n; i < m; i++)
    res[i] = complex<double>(0, 0);
  return m;
}

void FFT(complex<double> *const a, const int n, int forward) {
  for (int i = 1, j = n / 2, k = n / 2; i < n - 1; i++) {
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
      for (int k = i; k < i + len / 2; k++) {
        complex<double> u = a[k];
        complex<double> v = w * a[k + len / 2];
        a[k] = u + v;
        a[k + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (forward == -1)
    for (int i = 0; i < n; i++)
      a[i] /= n;
}

int f[8], g[8];
complex<double> cf[16], cg[16];

int main() {
  for (int i = 0; i < 6; i++)
    f[i] = i + 1;
  for (int i = 0; i < 7; i++)
    g[i] = (i + 1) * 10;

  int m = 16;
  to_complex(f, 6, cf, m);
  to_complex(g, 7, cg, m);

  FFT(cf, m, 1);
  FFT(cg, m, 1);

  for (int i = 0; i < m; i++)
    cf[i] *= cg[i];

  FFT(cf, m, -1);
  for (auto i: cf)
    cout << i << " ";

  return 0;
}
