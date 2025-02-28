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

    TreeNode* find_inor_pre(TreeNode* root){
        while(root -> right) root = root -> right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root -> val == key){
            if(!root -> left && !root -> right) return nullptr;
            else if(!root -> left) return root -> right;
            else if(!root -> right) return root -> left;
            else{
                TreeNode * child = find_inor_pre(root -> left);
                root -> val = child -> val;
                root -> left = deleteNode(root -> left , child -> val);
                return root;
            }
        }
        if(root -> val < key) root -> right = deleteNode(root -> right , key);
        else root-> left = deleteNode(root -> left , key);
        return root;
    }
};