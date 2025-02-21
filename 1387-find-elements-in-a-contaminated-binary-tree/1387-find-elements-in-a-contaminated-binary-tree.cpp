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
class FindElements {
public:

    TreeNode * root;

    void solve(TreeNode * root , int value){
        if(!root->left && !root->right) return;
        
        if(root -> left){
            root -> left -> val = 2 * value + 1;
            solve(root -> left , root -> left -> val);
        }

        if(root -> right){
            root -> right -> val = 2 * value + 2;
            solve(root -> right , root -> right -> val);
        }
    }

    FindElements(TreeNode* root) {
        if(!root) return;
        this -> root = root;
        root->val = 0;
        solve(root  , root -> val);
    }
    
    bool find(int target) {

        if(!root) return false;

        if(target == root->val) return true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* top = q.front();
            if( target == top->val) return true;
            q.pop();
            if(top -> left) q.push(top -> left);
            if(top -> right) q.push(top -> right);
        }
        return false;

    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */