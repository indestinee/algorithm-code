class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), s[n], cnt[n], top = -1;
        for( int i = 0 ; i < n ; i ++ ){
            while( top != -1 && heights[s[top]] >= heights[i] )
                top --;
            cnt[i] = i - ( top == -1 ? -1 : s[top] );
            s[++top] = i;
        }
        top = -1;
        int S = 0;
        for( int i = n - 1 ; i + 1 ; i -- ){
            while( top != -1 && heights[s[top]] >= heights[i] )
                top --;
            S = max( S , ( ( top == -1 ? n : s[top] ) - 1 - i + cnt[i] ) * heights[i] ); 
            s[++top] = i;
        }
        return S;
    }
};
