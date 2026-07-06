// Last updated: 7/6/2026, 12:03:04 PM
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
    int maxi = 0;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;

        int left = 0;
        int right = 0;

        // maxi = max(maxi, )
        return 1 + max(left+solve(root->left), right + solve(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return solve(root);
    }
};