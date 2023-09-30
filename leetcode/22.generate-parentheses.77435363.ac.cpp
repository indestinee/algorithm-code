class Solution {
    
public:
    vector<string> generateParenthesis(int n) {
        n <<= 1;
        int *a = (int*) malloc(n << 2);
        vector<string> ans;
        for (unsigned int i = 0, m = 1 << n; i < m;) {
            string tmp = "";
            int x = i, cnt = 0, ok = 1;
            if (__builtin_popcount(x) << 1 != n) {
                i++;
                continue;
            }
            for (int j = 0; j < n; j++) {
                a[j] = x & 1;
                x >>= 1;
            }
            
            for (int j = n - 1; ~j; j--) {
                if (a[j] == 0) {
                    cnt++;
                } else {
                    cnt--;
                }
                if (cnt < 0) {
                    i += 1 << j;
                    i &= (0xffffffff) - (1 << j);
                    ok = 0;
                    break;
                }
                tmp += char(a[j] + '(');
            }
            if (!ok)
                continue;
            ans.push_back(tmp);
            i++;
        }
        free(a);
        return ans;
    }
};
