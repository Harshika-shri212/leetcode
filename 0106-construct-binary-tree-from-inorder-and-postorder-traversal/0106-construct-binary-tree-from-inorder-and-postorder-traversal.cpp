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

            auto it = find(inorder.begin() , inorder.end() , root);
            int root_ind = distance(inorder.begin() , it);

            TreeNode* newNode = new TreeNode(root);

            vector<int> left_tree(inorder.begin() , inorder.begin() + root_ind);
            vector<int> right_tree(inorder.begin() + root_ind + 1 , inorder.end());

            newNode -> right = tree(q , right_tree);
            newNode -> left = tree(q , left_tree);

            return newNode;
        }
        return nullptr;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin() , postorder.end());
        deque<int> q(postorder.begin() , postorder.end());
        return tree(q , inorder);
    }
};