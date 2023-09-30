class Solution {
public:
    void moveZeroes(vector<int>& v) {
        for (int i = 0, j = 0, n = v.size(); j < n; j++)
            if (v[j])
                swap(v[i++], v[j]);
    }
};
