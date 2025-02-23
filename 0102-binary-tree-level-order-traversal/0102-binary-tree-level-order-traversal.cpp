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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        vector<int> v = {root -> val};
        res.push_back(v);

        q.push(root);

        while(!q.empty()){
            vector<int> v;
            int count = q.size();

            while(count--){
                TreeNode* top = q.front();
                q.pop();

                if(top -> left){
                    v.push_back(top -> left -> val);
                    q.push(top -> left);
                }

                if(top -> right){
                    v.push_back(top -> right -> val);
                    q.push(top -> right);
                }

            }
            if(v.size() != 0) res.push_back(v);
        }

        return res;  
    }
};