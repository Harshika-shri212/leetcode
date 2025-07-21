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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;

        vector<int>arr;

        if(root){
            st.push(root);
        }

        while(!st.empty()){
            TreeNode* fr = st.top();
            st.pop();
            arr.push_back(fr -> val);
            if(fr -> right) st.push(fr -> right);
            if(fr -> left) st.push(fr -> left);
        }

        return arr;
    }
};