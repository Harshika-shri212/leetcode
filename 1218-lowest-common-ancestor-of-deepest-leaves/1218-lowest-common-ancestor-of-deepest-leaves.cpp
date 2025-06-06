class Solution {
public:

     pair<TreeNode*, int> func(TreeNode* root){
        if (!root) return {nullptr, 0};
        
        TreeNode* node;
        int dep;

        if(!root->left && root->right){
            auto res = func(root -> right);
            return {res.first, res.second + 1};
        }

        if(!root->right && root->left){ 
            auto res = func(root -> left);
            return {res.first, res.second + 1};
        }

        if(!root->left && !root->right){
            return {root, 1}; 
        }

       
        auto res1 = func(root -> left);
        auto res2 = func(root -> right);
        if(res1.second == res2.second) return {root, res1.second + 1};
        else if(res1.second > res2.second) return {res1.first, res1.second + 1};
        else return {res2.first, res2.second + 1};
     }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto result = func(root);
        return result.first;
    }
};
