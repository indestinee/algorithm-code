/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.31%)
 * Total Accepted:    627.1K
 * Total Submissions: 2.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
#ifdef LOCAL


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail=NULL;
        int x = 0;
        while (l1 && l2) {
            x = l1->val + l2->val + x;
            if (head == 0) {
                head = tail = new ListNode(x%10);
            } else {
                tail->next = new ListNode(x%10);
                tail = tail->next;
            }
            l1 = l1->next, l2 = l2->next;
            x /= 10;
        }
        while (l1) {
            x = l1->val + x;
            tail->next = new ListNode(x%10);
            tail = tail->next;
            l1 = l1->next;
            x /= 10;
        }
        while (l2) {
            x = l2->val + x;
            tail->next = new ListNode(x%10);
            tail = tail->next;
            l2 = l2->next;
            x /= 10;
        }
        while (x) {
            tail->next = new ListNode(x % 10);
            x /= 10;
        }
        return head;

    }
};
#ifdef LOCAL
int main() {
    


    return 0;
}
#endif


