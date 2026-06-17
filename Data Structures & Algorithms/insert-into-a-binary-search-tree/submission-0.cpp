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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode* cur = root;
        TreeNode* parent = nullptr;

        while(cur) {
            parent = cur;
            if(val < cur -> val) cur = cur -> left;
            else cur = cur -> right;
        }

        TreeNode* node = new TreeNode(val);
        if(val < parent -> val){
            parent -> left = node;
        }
        else{
            parent -> right = node;
        }

        return root;
    }
};