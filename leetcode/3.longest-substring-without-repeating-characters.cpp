/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.15%)
 * Total Accepted:    619.7K
 * Total Submissions: 2.5M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

int cnt[128];
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        memset(cnt, 0, sizeof cnt);
        int ans = 0;
        for (int i = 0, j = 0; j < int(s.length()); j++) {
            if (++cnt[int(s[j])] > 1)
                while (cnt[int(s[j])] > 1)
                    --cnt[int(s[i++])];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
