const int maxe = 1000010, maxn = 510;
int dist[maxn], q[maxn], good[maxn];
struct node{
    int v;
    node *nxt;
} p[maxe], *pointer[maxe];

inline int work(const vector<vector<int>>& routes, const int &S, const int &T) {
    int l = 0, r = 0;
    for (node *yy = pointer[S]; yy; yy = yy->nxt) {
        int i = yy->v;
        if (good[i])
            return 1;
        dist[i] = 1;
        q[r++] = i;
    }
    pointer[S] = 0;
            
    while (l < r) {
        auto x = q[l++];
        for (auto element: routes[x]) {
            for (node *yy = pointer[element]; yy; yy = yy->nxt) {
                int y = yy->v;
                if (dist[y] == -1) {
                    dist[y] = dist[x] + 1;
                    if (good[y])
                        return dist[y];
                    q[r++] = y;
                }
            }
            pointer[element] = 0;
        }
    }
    return -1;
}
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;
        int cnt = 0;
        memset(pointer, 0, sizeof pointer);
        memset(good, 0, sizeof good);
        memset(dist, -1, sizeof dist);

        for (int i = 0; i < int(routes.size()); i++) {
            auto route = routes[i];
            for (int j = 0; j < int(route.size()); j++) {
                auto x = route[j];

                p[cnt].v = i;
                p[cnt].nxt = pointer[x];
                pointer[x] = &p[cnt++];

                if (x == T)
                    good[i] = 1;
            }
        }
        return work(routes, S, T);
    }
};
