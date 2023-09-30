class Solution {
public:
    string largestNumber(vector<int>& nums) {
        char buff[128];
        vector<string> s;
        for (auto n: nums) {
            sprintf(buff, "%d%d", n, n);
            s.push_back(string(buff));
        }
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        string ans = "";
        for (auto &i: s) {
            i[i.length()>>1] = 0;
            ans += string(i.c_str());
        }
        if (ans[0] == '0')
            return "0";
        return ans;
    }
};
