/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode *now = head, *bef = head;
		for(int i = 0; i < k; i++) {
			now = now->next;
		}
		while(now->next != NULL) {
			now = now->next;
			bef = bef->next;
		}
		bef->next->next = head;
		now = bef->next;
		bef->next = NULL;
		return now;
	}
};
