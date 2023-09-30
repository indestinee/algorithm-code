int dp[2][1010];
class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(), *now = dp[0], *bef = dp[1];
        memset(now, 0, (m+1) << 2);
        for (int i = 0; i < n; i++) {
            swap(now, bef);
            now[0] = 0;
            for (int j = 0; j < m; j++) 
                now[j+1] = max(bef[j+1], max(now[j], (a[i] == b[j]) ? bef[j] + 1: 0));
        }
        return now[m];
    }
};
