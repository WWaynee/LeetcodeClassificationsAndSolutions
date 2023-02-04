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
    TreeNode* cur = nullptr;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (root == nullptr) return false;
        int up = 0, left = 0, right = 0;
        if (root->val == x) {
            left = dfs(root->left, x);
            right = n - left - 1;
            return (left > right + 1 || right > left + 1);
        }
        up = dfs(root, x);
        left = dfs(cur->left, x);
        right = n - left - up - 1;
        return (up > left + right + 1 || left > right + up + 1 || right > left + up + 1);
    }

    int dfs(TreeNode* root, int x) {
        if (root == nullptr) return 0;
        if (cur == nullptr && root->val == x) {
            cur = root;
            return 0;
        }
        return 1 + dfs(root->left, x) + dfs(root->right, x);
    }
};