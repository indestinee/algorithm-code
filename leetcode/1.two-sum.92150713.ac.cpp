class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = nums;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j;) {
            if (nums[i] + nums[j] > target) {
                j--;
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                vector<int> ans;
                for (int k = 0; k < v.size(); k++) 
                    if (v[k] == nums[i] || v[k] == nums[j])
                        ans.push_back(k);
                return ans;
            }
        }
    }
};
