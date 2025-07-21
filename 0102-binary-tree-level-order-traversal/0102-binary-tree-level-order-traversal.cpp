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
        vector<vector<int>>arr;
        queue<TreeNode*>q;

        if(root) q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            while(n--){
                TreeNode* fr = q.front();
                q.pop();
                if(fr -> left) q.push(fr -> left);
                if(fr -> right)q.push(fr -> right);
                v.push_back(fr -> val);
            }
            if(v.size() > 0) arr.push_back(v);
        }

        return arr;
    }
};