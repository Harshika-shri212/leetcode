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

    void solve(TreeNode* root, int targetSum , vector<int> &cur , vector<vector<int>> &res ){
        if(!root) return;
        cur.push_back(root -> val);
        if(!root -> left && !root -> right && targetSum == root -> val){
            res.push_back(cur);
        }
        
        else{
            solve(root ->left , targetSum - root -> val , cur , res);
            solve(root -> right , targetSum - root -> val , cur , res);
        }
        cur.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        vector<vector<int>> res;
        solve(root , targetSum , cur , res);
        return res;
    }
};