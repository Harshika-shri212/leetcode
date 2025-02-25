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

    TreeNode* tree(deque<int> & q , vector<int>& inorder){
        if(!inorder.empty()){
            int root = q.front();
            q.pop_front();

            auto it  = find(inorder.begin() , inorder.end() , root);
            int root_ind  = distance(inorder.begin() , it);

            vector<int>left_tree(inorder.begin() , inorder.begin() + root_ind);
            vector<int>right_tree(inorder.begin() + root_ind + 1 , inorder.end());

            TreeNode* newNode = new TreeNode(root);
            newNode -> left = tree(q , left_tree);
            newNode -> right = tree(q , right_tree);

            return newNode;
        }
        return nullptr;
    }

    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         deque<int> q(preorder.begin() , preorder.end());
         return tree(q , inorder);
    }
};