#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int n, m;
long long a[maxn];
vector<int> a_by_cnt[maxn];
set<pair<int, int>> bad;
map<int, int> cnt;
vector<int> valid_cnt;

void work() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    cnt[a[i]]++;
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    bad.insert({x, y});
    bad.insert({y, x});
  }

  for (auto i = cnt.rbegin(); i != cnt.rend(); i++) {
    a_by_cnt[i->second].push_back(i->first);
    valid_cnt.push_back(i->second);
  }

  sort(valid_cnt.begin(), valid_cnt.end());
  valid_cnt.resize(unique(valid_cnt.begin(), valid_cnt.end()) -
                   valid_cnt.begin());

  long long maxi = 0;

  for (long long count : valid_cnt) {
    for (long long val : a_by_cnt[count]) {

      bool updated = false;
      for (long long c : valid_cnt) {
        if (c > count) {
          break;
        }
        for (long long v : a_by_cnt[c]) {
          if (bad.find({val, v}) != bad.end() || val == v) {
            continue;
          }
          maxi = max(maxi, (v + val) * (c + count));
          updated = true;
          break;
        }
      }
    }
  }

  cout << maxi << endl;

  for (int i = 0; i <= n; i++) {
    a_by_cnt[i].clear();
  }
  bad.clear();
  cnt.clear();
  valid_cnt.clear();
}

int main() {

  int cas;
  scanf("%d", &cas);
  for (int _cas = 1; _cas <= cas; _cas++) {

    work();
  }

  return 0;
}
