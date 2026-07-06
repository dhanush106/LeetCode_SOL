// Last updated: 7/6/2026, 12:03:00 PM
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
    //Brute force
    // int solve(TreeNode* root){
    //     if(root == NULL) return 0;

    //     return 1+max(solve(root->left), solve(root->right));
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root == NULL) return true;

    //     int lh = solve(root->left);
    //     int rh = solve(root->right);

    //     if(abs(lh-rh)>1) return false;

    //     return isBalanced(root->left) && isBalanced(root->right);
    // }


    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int lh = solve(root->left);
        if(lh == -1) return -1;

        int rh = solve(root->right);
        if(rh == -1) return -1;

        if(abs(lh-rh)>1) return -1;

        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;

        return (solve(root) != -1);
    }
};