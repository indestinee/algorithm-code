int dp[1010][1010];
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans = 0, n = a.size();
        memset(dp, 0, sizeof dp);
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = 2;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i-1] == a[i]) {
                cnt++;
            } else {
                cout << cnt << endl;
                ans += (1 << cnt) - cnt - cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        ans += (1 << cnt) - cnt - cnt * (cnt - 1) / 2 - 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = i + 2; j < n && k < n;) {
                if (a[i] == a[j]) {
                    j++;
                    continue;
                }
                while (k < n && a[k] - a[j] < a[j] - a[i])
                    k++;
                if (k == n)
                    break;
                if (a[k] - a[j] == a[j] - a[i]) {
                    dp[j][k] = dp[i][j] + 1;
                    ans += max(0, dp[j][k] - 2);
                    k++;
                } else {
                    j++;
                    if (k <= j)
                        k++;
                }
            }
        }
        return ans;
    }
};
