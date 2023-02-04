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
    int ans = 0;
    //0：该节点被监控自己安；1：该节点不被监控；2：该节点被监控但自己不安
    int dfs(TreeNode *root){
        if(root==NULL) return 2;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left==1 || right==1){
            ans++;return 0;
        }
        if(left==0 || right==0) return 2;
        else return 1;
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        if(dfs(root)==1) ans++;
        return ans;
    }
};