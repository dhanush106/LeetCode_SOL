// Last updated: 7/6/2026, 12:03:05 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;

        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(flag){
                    temp[i] = curr->val;
                }else{
                    temp[size-i-1] = curr->val;
                }
            }
            flag = !flag;
            ans.push_back(temp);
            cout<<" ITERATION ::: "<<flag<<endl;
        }
        return ans;
    }
};