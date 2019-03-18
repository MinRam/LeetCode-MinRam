/**
 * @Problem https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * @Author  MinRam
 * @Date    03/19/2019
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (nullptr == head) return nullptr;

		ListNode * root = new ListNode(0);
		root->next = head;

		for (int i = 0; i < n; ++i) {
			if (nullptr == head) return nullptr;
			else head = head->next;
		}

		ListNode * pre = root;

		while (nullptr != head) {
			head = head->next;
			pre = pre->next;
		}

		removeNode(pre);

		return root->next;
	}
	void removeNode(ListNode * head) {
		ListNode * node = head->next;
		head->next = node->next;
		delete node;
	}
};