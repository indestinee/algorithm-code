#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'smellCosmos' function below.
 *
 * The function is expected to return a long long_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. long long_INTEGER_ARRAY a
 *  2. long long_INTEGER_ARRAY b
 */

const long long p = 1e9 + 9;

const long long mods[3] = {998244353, 1004535809, 469762049}, gs[3] = {3, 3, 3};

inline __int128 quick_pow128(__int128 x, __int128 b, __int128 mod) {
  __int128 res(1);
  while (b) {
    if (b & 1)
      res = res * x % mod;
    x = x * x % mod;
    b >>= 1;
  }
  return res;
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

void NTT(long long *a, int *r, int n, long long g, long long mod, int forward) {

  for (int i = 0; i < n; i++)
    if (r[i] < i)
      swap(a[i], a[r[i]]);

  for (int len = 2; len <= n; len <<= 1) {
    long long wlen = quick_pow(g, (mod - 1) / len, mod);
    for (int i = 0; i < n; i += len) {
      long long w = 1;
      for (int k = i; k < i + len / 2; k++) {
        long long u = a[k], v = w * a[k + len / 2] % mod;
        a[k] = (u + v) % mod;
        a[k + len / 2] = (u - v + mod) % mod;
        w = w * wlen % mod;
      }
    }
  }

  if (forward == -1) {
    reverse(a + 1, a + n);
    long long inv_n = quick_pow(n, mod - 2, mod);
    for (int i = 0; i < n; i++)
      a[i] = a[i] * inv_n % mod;
  }
}

inline __int128 crt(__int128 r1, __int128 r2, __int128 m1, __int128 m2,
                    __int128 im1, __int128 im2) {
  return (r1 * im2 % m1 * m2 + r2 * im1 % m2 * m1) % (m1 * m2);
}

vector<long long> smellCosmos(vector<long long> a, vector<long long> b) {
  // Write your code here
  vector<long long> nas[3];
  vector<long long> nbs[3];

  int n = a.size() << 1;
  vector<int> r(n);
  for (int i = 0; i < n; i++)
    r[i] = (i & 1) * (n >> 1) | (r[i >> 1] >> 1);

  for (int i = 0; i < 3; i++) {
    nas[i].resize(n);
    nbs[i].resize(n);
    for (int j = 0; j < n / 2; j++)
      nas[i][j] = a[j];
    for (int j = 0; j < n / 2; j++)
      nbs[i][j] = b[j];
    NTT(nas[i].data(), r.data(), n, gs[i], mods[i], 1);
    NTT(nbs[i].data(), r.data(), n, gs[i], mods[i], 1);
    for (int j = 0; j < n; j++)
      nas[i][j] = nas[i][j] * nbs[i][j] % mods[i];
    NTT(nas[i].data(), r.data(), n, gs[i], mods[i], -1);
  }
  __int128 im0 = quick_pow(mods[0], mods[1] - 2, mods[1]),
           im1 = quick_pow(mods[1], mods[0] - 2, mods[0]),
           im2 = quick_pow128(mods[0] * mods[1], mods[2] - 2, mods[2]),
           im3 = quick_pow128(mods[2], (mods[0] - 1) * (mods[1] - 1) - 1,
                              mods[0] * mods[1]);

  vector<long long> ans(n - 1);
  for (int i = 0; i < n - 1; i++) {
    nas[0][i] = crt(nas[0][i], nas[1][i], mods[0], mods[1], im0, im1);
    __int128 tmp =
        crt(nas[0][i], nas[2][i], mods[0] * mods[1], mods[2], im2, im3);
    ans[i] = tmp % p;
  }
  return ans;
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split(rtrim(a_temp_temp));

  vector<long long> a(n + 1);

  for (int i = 0; i < n + 1; i++) {
    long long a_item = stol(a_temp[i]);

    a[i] = a_item;
  }

  string b_temp_temp;
  getline(cin, b_temp_temp);

  vector<string> b_temp = split(rtrim(b_temp_temp));

  vector<long long> b(n + 1);

  for (int i = 0; i < n + 1; i++) {
    long long b_item = stol(b_temp[i]);

    b[i] = b_item;
  }

  vector<long long> result = smellCosmos(a, b);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << " ";
    }
  }

  cout << "\n";

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
