// Last updated: 7/6/2026, 12:03:08 PM
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
bool solve(TreeNode* p,TreeNode*q)
{
     if(p==NULL&& q==NULL) return true;
    if(p==NULL||q==NULL) return false;
   
    if(p->val!=q->val) return false;
    return (p->val==q->val)&&solve(p->left,q->right)&&solve(p->right,q->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
     if(   solve(root->left,root->right))
     {
        return true;
     }
return false;
    }
};