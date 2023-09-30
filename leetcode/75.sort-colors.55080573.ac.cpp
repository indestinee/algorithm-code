class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        for( int i = 0 ; i < 3 ; i ++ )
            cnt[i] = 0;
        for( int i = 0 , sz = nums.size() ; i < sz ; i ++ )
            cnt[nums[i]] ++;
        nums.clear();
        for( int i = 0 ; i < 3 ; i ++ )
            while( cnt[i] -- )
                nums.push_back( i );
    }
};
