class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int x = int(dividend < 0) ^ int(divisor < 0);
        if (dividend < 0)
            dividend = -dividend;
        if (divisor < 0)
            divisor = - divisor;
        
        long long sub, ans=0, cnt=1;
        for (sub = divisor; (sub<<1) <= dividend; sub<<=1, cnt<<=1);
        for (; sub >= divisor; sub >>=1, cnt >>=1) {
            if (dividend >= sub) {
                dividend -= sub;
                ans += cnt;
            }
        } 
        cout << ans << " " << x << endl;
        if (x)
            return -ans;
        return min(ans, (1LL << 31) - 1);
    }
};
