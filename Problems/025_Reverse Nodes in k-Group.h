/**
 * @Problem https://leetcode.com/problems/reverse-nodes-in-k-group/
 * @Author MinRam
 * @Date  08/22/2019
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution {
public:
	vector<ListNode*> s;
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head)return nullptr;
		ListNode *cur = head;
		for (int i = 0; i < k; ++i)
			if (cur)
			{
				s.push_back(cur);
				cur = cur->next;
			}
			else
				break;
		if (s.size() == k)
		{
			ListNode *next = s[k - 1]->next;
			ListNode *new_head = s[k - 1];
			ListNode *new_tail = s[0];
			for (int i = k - 1; i > 0; --i)
				s[i]->next = s[i - 1];
			s.clear();
			if (next)
				new_tail->next = reverseKGroup(next, k);
			else
				new_tail->next = nullptr;
			return new_head;

		}
		else
			return head;
	}
};
