/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        
        while(root||s.size()>0){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            k--;
            if(k==0){
                break;
            }
            root=root->right;
        }
        return root->val;
    }
};

 
// @lc code=end

