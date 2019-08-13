/**
 * @Problem https://leetcode.com/problems/merge-k-sorted-lists/
 * @Author MinRam
 * @Date  04/20/2019
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
 public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret, *curr;
        if (l2 == NULL)
            return l1;
        if (l1 == NULL)
            return l2;
        if (l1->val < l2->val) {
            ret = l1;
            l1 = l1->next;
        } else {
            ret = l2;
            l2 = l2->next;
        }
        curr = ret;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return ret;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() & 1)
            lists.push_back(NULL);
        for (int i = 0; i < lists.size()/2; ++i) {
            lists[i] = mergeTwoLists(lists[i*2], lists[i*2+1]);
        }
        lists.resize(lists.size()/2);
        if (lists.size() == 1)
            return lists[0];
        else
            return mergeKLists(lists);
    }
};