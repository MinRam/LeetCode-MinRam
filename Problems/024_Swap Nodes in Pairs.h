/**
 * @Problem https://leetcode.com/problems/swap-nodes-in-pairs/
 * @Author MinRam
 * @Date  08/13/2019
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
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr
			|| head->next == nullptr)
			return head;

		ListNode vir_head(-1);
		vir_head.next = head;
		ListNode * currentNode = &vir_head;

		while (currentNode->next != nullptr
			&& currentNode->next->next != nullptr) {
			ListNode * preNode = currentNode->next;
			ListNode * lasNode = currentNode->next->next;

			// swap nodes between preNode and lasNode
			currentNode->next = lasNode;
			preNode->next = lasNode->next;
			lasNode->next = preNode;

			// go to the next window
			currentNode = preNode;
		}

		return vir_head.next;
	}
};