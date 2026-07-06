// Last updated: 7/6/2026, 12:02:05 PM
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
    vector<vector<int>> paths;

    void dfs(TreeNode* root, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right) {
            paths.push_back(path);
        }

        dfs(root->left, path);
        dfs(root->right, path);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);

        vector<string> ans;

        for (auto &p : paths) {
            string s = "";

            for (int i = 0; i < p.size(); i++) {
                s += to_string(p[i]);

                if (i != p.size() - 1)
                    s += "->";
            }

            ans.push_back(s);
        }

        return ans;
    }
};