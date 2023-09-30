int cnt[128];

class Solution {
public:
    Solution() {
        cnt['('] = 1;
        cnt['{'] = 2;
        cnt['['] = 3;
        cnt[')'] = -1;
        cnt['}'] = -2;
        cnt[']'] = -3;
    }
    bool isValid(string s) {
        stack<int> v;
        for (auto &i: s) {
            int x = cnt[int(i)];
            if (x > 0) {
                v.push(x);
            } else {
                if (!v.empty() && v.top() + x == 0) {
                    v.pop();
                } else {
                    return 0;
                }
            }
        }
        return v.empty();
    }
};
