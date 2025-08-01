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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>arr;
        stack<TreeNode*>st;

        TreeNode* node = root;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty()) break;
                TreeNode* fr = st.top();
                st.pop();
                arr.push_back(fr -> val);
                node = fr -> right;
            }
        }
        return arr;
    }
};