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
    int maxn = 0;
    int dfs(TreeNode* root){//len(root)=dfs(root->left)+dfs(root->right)+1;
        if(root==NULL) return 0;
        int lh = 0,rh = 0;
        if(root->left!=NULL) lh = dfs(root->left);
        if(root->right!=NULL) rh = dfs(root->right);
        maxn = max(maxn,lh+rh+1);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxn-1;
    }
};