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
    map<TreeNode*,int> nor;//记录某结点不被偷时的最大值
    map<TreeNode*,int> r;//记录某结点被偷时的最大值
    //每个结点有两种状态，偷和不偷
    void dfs(TreeNode* root){
        if(root==NULL) return ;
        if(root->left!=NULL) dfs(root->left);//计算左子树
        if(root->right!=NULL) dfs(root->right);//计算右子树
        //计算当前结点不偷的最大值
        int res1 = max(nor[root->left],r[root->left]) + max(nor[root->right],r[root->right]);
        //计算当前结点被偷的最大值
        int res2 = nor[root->left] + nor[root->right] + root->val;
        //记录结果
        nor[root] = res1; r[root] = res2;
        maxn = max(maxn,max(res1,res2));
    }
    int rob(TreeNode* root) {
        nor[NULL] = 0; r[NULL] = 0;
        dfs(root);
        return maxn;
    }
};