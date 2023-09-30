/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.63%)
 * Total Accepted:    396.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void manacher(const char* s, int *pr, const int &n) {

}

class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> pr(s.length());
        manacher(s.c_str(),  &pr[0], s.length());
        manacher(a, s, s);



        string ans = "";
        return ans;
    }
};
#ifdef DEBUG
int main() {
}

#endif

