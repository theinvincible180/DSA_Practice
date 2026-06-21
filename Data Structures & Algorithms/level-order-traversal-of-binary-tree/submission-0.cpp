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
    // vector<vector<int>> traverse(TreeNode* root, queue<TreeNode*> qt) {
    //     if() return
    // } 
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> qt;
        qt.push(root);
        vector<vector<int>> result;

        while(!qt.empty()) {
            // TreeNode* node = qt.front();
            int n = qt.size();
            vector<int> temp;

            for(int i = 0 ; i < n ; i++) {
                TreeNode* node = qt.front();
                qt.pop();
                temp.push_back(node -> val);

                if(node->left) qt.push(node->left);
                if(node->right) qt.push(node->right);
            }

            result.push_back(temp);
        }

        return result;
    }
};
