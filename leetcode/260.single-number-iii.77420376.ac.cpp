class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0, a1 = 0, a2 = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        res = -res & res;
        for (int i = 0; i < n; i++) {
            if (nums[i] & res) {
                a1 ^= nums[i];
            } else {
                a2 ^= nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};
