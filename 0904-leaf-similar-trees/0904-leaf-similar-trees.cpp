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

    void findLeaf(TreeNode* & root , vector<int> & v){
        if(!root) return;
        if(!root -> left && !root -> right) v.push_back(root -> val);
        findLeaf(root -> left , v);
        findLeaf(root -> right , v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        findLeaf(root1 , v1);
        findLeaf(root2 , v2);

        return v1 == v2;
    }
};