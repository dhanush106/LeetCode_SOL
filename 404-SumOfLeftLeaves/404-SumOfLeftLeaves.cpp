// Last updated: 7/6/2026, 12:01:43 PM
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
    bool isLeaf(TreeNode* root){
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) return true;
        else{
            return false;
        }
    }
    void solve(TreeNode* root){
        if(root == NULL) return;
        if((root != NULL) && (root->left != NULL) && isLeaf(root->left)){
            ans += root->left->val;
        }
        solve(root->left);
        solve(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root);
        return ans;
    }
};