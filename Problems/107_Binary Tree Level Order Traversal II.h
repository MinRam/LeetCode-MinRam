/**
 * @Problem https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * @Author  MinRam
 * @Date    03/30/2020
 * @tutorial none
 */
 static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        queue<int> level_q;
        int prev_level =-1;
        
        q.push(root);
        level_q.push(0);
        
        
        while(q.empty()==false){
            TreeNode* node = q.front();
            q.pop();
            int level = level_q.front();
            level_q.pop();
            
            if(node!=NULL){
                if(prev_level!=level){
                    prev_level = level;
                    vector<int> temp;
                    temp.push_back(node->val);
                    res.push_back(temp);
                }
                else{
                    res[prev_level].push_back(node->val);
                }
            }
            
            if(node->left!=NULL){
                q.push(node->left);
                level_q.push(level+1);
            }
            
            if(node->right!=NULL){
                q.push(node->right);
                level_q.push(level+1);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};