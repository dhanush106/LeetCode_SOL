// Last updated: 7/6/2026, 12:02:13 PM
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
    int count = 0;
    // void traverse(TreeNode* root){
    //     if(root->left){
    //         count++;
    //         traverse(root->left);
    //     }
    //     if(root->right){
    //         count++;
    //         traverse(root->right);
    //     }
    // }
    // int countNodes(TreeNode* root) {
    //     if(root == NULL) return count;
    //     traverse(root);
    //     return count + 1;
    // }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};