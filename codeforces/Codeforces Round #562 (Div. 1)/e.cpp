/*
 *  author:
 *      indestinee
 *  date:
 *      2019/06/03
 *  file name:
 *      e.cpp
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 4096*(4096+3) * 10, 
      maxm = 4096*(4096+3) + 10, inf = 1e9+7;


struct edge{
    int v, f, nxt;
    edge() {}
    edge(int v, int f, int nxt): v(v), f(f), nxt(nxt) {}
};


class dinic{
private:
    int nume, g[maxn], dist[maxn];
    edge e[maxm * 2];
    queue<int> q;
    bool vis[maxn];

    inline void bfs() {
        memset(dist, 0, sizeof dist);
        while (!q.empty())
            q.pop();

        vis[src] = true;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = g[u]; i; i = e[i].nxt) {
                if (e[i].f && !vis[e[i].v]) {
                    q.push(e[i].v);
                    dist[e[i].v] = dist[u] + 1;
                    vis[e[i].v] = true;
                }
            }
        }
    }

    int dfs(int u, int delta) {
        if (u == sink)
            return delta;
        int ret = 0;
        for (int i = g[u]; delta && i; i = e[i].nxt) {
            if (e[i].f && dist[e[i].v] == dist[u] + 1) {
                int dd = dfs(e[i].v, min(e[i].f, delta));
                e[i].f -= dd;
                e[i^1].f += dd;
                delta -= dd;
                ret += dd;
            }
        }
        return ret;
    }

public:
    int src, sink;
    inline void addedge(const int u, const int v, const int c) {
        e[++nume] = edge(v, c, g[u]);
        g[u] = nume;

        e[++nume] = edge(u, 0, g[v]);
        g[v] = nume;
    }
    inline void init() {
        memset(g, 0, sizeof g);
        nume = 1;
    }



    int maxflow() {
        int ret = 0;
        while (true) {
            memset(vis, 0, sizeof vis);
            bfs();
            if (!vis[sink])
                return ret;
            ret += dfs(src, inf);
        }
        return ret;
    }
};

int n, a[4096];
dinic d;
int main() {
    d.init();
    scanf("%d", &n);
    n = 1 << n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]); 



    return 0;
}
