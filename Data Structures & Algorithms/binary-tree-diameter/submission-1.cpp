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
    int depth(TreeNode* root) {
        if(!root) return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }

    void diameter(TreeNode* root, int& res){
        if(!root) return;

        res = max(res, depth(root->left) + depth(root->right));

        diameter(root->left, res);
        diameter(root->right, res);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;

        diameter(root, res);

        return res;
    }
};
