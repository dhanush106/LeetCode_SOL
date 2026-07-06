// Last updated: 7/6/2026, 2:12:32 PM
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

 //post order --> left,right,root
class Solution {
public:
    void postorder(TreeNode* root, vector<int> &res){
        if(root == NULL) return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
};