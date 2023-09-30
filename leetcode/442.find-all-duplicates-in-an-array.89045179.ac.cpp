class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        bool *vis = new bool[n + 1];
        memset(vis, 0, n + 1);
        vector<int> ans;
        for (auto i: nums) {
            if (vis[i])
                ans.push_back(i);
            vis[i] = true;
        }
        return ans;
    }
};
