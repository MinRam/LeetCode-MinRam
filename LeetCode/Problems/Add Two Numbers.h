
/**
 * @Problem https://leetcode.com/problems/add-two-numbers/
 * @Author MinRam
 * @Date  02/22/2019
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 该串功能相见参考[2]
static const auto __ = [](){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 return nullptr;
}();

class Solution {
public:
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 ListNode* res = new ListNode(0); // 仅为了代码方便，多申请了个头节点
 ListNode* cur = res;
 int cBit = 0; // 进位标识 1：进位；0：不进位；

 while (l1 != nullptr || l2 != nullptr){
 int sum = ((l1 != nullptr)?(l1->val):(0)) + ((l2 != nullptr)?(l2->val):(0)) + cBit;
 cBit = sum >= 10; // 由于sum<20,所以没必要使用 cBit = sum/10
 cur->next = new ListNode(sum>=10?sum-10:sum); // 同上理由
 cur = cur->next;
 if (l1 != nullptr) l1 = l1->next;
 if (l2 != nullptr) l2 = l2->next;
 }
 if (cBit)
 cur->next = new ListNode(cBit); // 处理最后以为进位的1
 /* 处理头节点的无效值
 cur = res->next;
 delete res;
 return cur;
 */


 return res->next;
 }
};