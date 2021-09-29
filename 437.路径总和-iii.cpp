/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans,t;
    unordered_map<int,int> m;
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        ans=0;
        t=targetSum;
        
    //     dfs1(root);
    //     return ans;
    // }
    //方法一是对每个节点，计算从该节点开始往下找看能否找到符合的节点
    // void dfs1(TreeNode* root){
    //     if(root==NULL)return;
    //     dfs2(root,root->val);
    //     dfs1(root->left);
    //     dfs1(root->right);
    // }
    // void dfs2(TreeNode* root,int val){
    //     if(val==t)ans++;
    //     if(root->left)dfs2(root->left,val+root->left->val);
    //     if(root->right)dfs2(root->right,val+root->right->val);
    // }
        // 前缀和中, [a, b] = [0, b] - [0, a-1] 。因此需要虚拟节点
        m[0]=1;
        dfs(root,root->val);
        return ans;
    }
    void dfs(TreeNode* root,int val){
        //// 以 当前节点 b 为 终点。
        if(m.count(val-t))ans+=m[val-t];
        m[val]++;
        //以 当前节点 b 为路径的一部分。
        if(root->left)dfs(root->left,val+root->left->val);
        if(root->right)dfs(root->right,val+root->right->val);
        //当子树结束时，应当把子树从哈希表中移除 (回溯即可)。避免跨两个方向的路径
        m[val]--;
    }
};
// @lc code=end

