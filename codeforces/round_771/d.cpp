#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;

struct Ans {
  int x, y, color;
  Ans(int x, int y, int color) : x(x), y(y), color(color) {}
};

int n, m, a[maxn][maxn], vis[maxn][maxn];
queue<pair<int, int>> q;
vector<Ans> v;

int ok(int x, int y) {
  // x [1, n), y [1, m)
  if (x >= 1 && x < n && y >= 1 && y < m) {
    if (vis[x][y]) {
      return -1;
    }

    int color = 0;
    for (int i = x; i <= x + 1; i++) {
      for (int j = y; j <= y + 1; j++) {
        if (color != 0 && a[i][j] != 0 && color != a[i][j]) {
          return -1;
        }
        if (a[i][j] != 0) {
          color = a[i][j];
        }
      }
    }

    return color;
  }
  return -1;
}

void paint(int x, int y, int color) {
  if (color != 0) {
    v.push_back(Ans(x, y, color));
  }
  for (int i = x; i <= x + 1; i++) {
    for (int j = y; j <= y + 1; j++) {
      a[i][j] = 0;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  int cnt = (n - 1) * (m - 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int color = ok(i, j);
      if (color != -1) {
        vis[i][j] = 1;
        paint(i, j, color);
        cnt--;
        q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    int x = front.first, y = front.second;
    for (int i = x - 1; i <= x + 1; i++) {
      for (int j = y - 1; j <= y + 1; j++) {
        int color = ok(i, j);
        if (color != -1) {
          vis[i][j] = 1;
          paint(i, j, color);
          cnt--;
          q.push({i, j});
        }
      }
    }
  }

  if (cnt != 0) {
    puts("-1");
  } else {
    reverse(v.begin(), v.end());
    printf("%d\n", int(v.size()));
    for (auto i : v) {
      printf("%d %d %d\n", i.x, i.y, i.color);
    }
  }

  return 0;
}
