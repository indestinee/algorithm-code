class Solution {
public:
    int gray( int x ){
        int a[30], cnt = 0;
        while( x ){
            a[cnt++] = x & 1;
            x >>= 1;
        }
        a[cnt] = 0;
        int res = 0;
        for( int i = 0 ; i < cnt ; i ++ )
            res |= ( a[i] ^ a[i+1] ) << i;
        return res;
    }
    vector<int> grayCode(int n) {
        vector<int> v;
        int m = 1 << n;
        for( int i = 0 ; i < m ; i ++ )
            v.push_back( gray( i ) );
        return v;
    }
};
