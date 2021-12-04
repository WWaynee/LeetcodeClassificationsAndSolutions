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
    //总体最大由局部最大得到
    int maxn = -9999;//最大值
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        maxn = max(maxn,max(left+right+root->val,max(left+root->val,max(right+root->val,root->val))));
        return max(left+root->val,max(right+root->val,root->val));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxn;
    }
};