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

    void addNode(unordered_map<int , TreeNode*> &m , int & lvl , TreeNode * & newNode){
        if (m.count(lvl - 1) && m[lvl - 1] != nullptr){
            if( m[lvl - 1] -> left == NULL){
                m[lvl - 1] -> left = newNode;
            }
            else m[lvl - 1] -> right = newNode;
        } 
    }

    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int , TreeNode*> m;
        int lvl = 0;

        int j = 0;
        string first = "";
        while(traversal[j] != '-' && j < traversal.size()){
            first = first + string(1 , traversal[j]);
            j += 1;
        }
        TreeNode *head = new TreeNode(stoi(first));
        m[0] = head;

        int i = j;
        while(i < traversal.size() ){
            if(traversal[i] == '-') {
                lvl += 1;
                i += 1;
            }
            else{
                string num = string(1, traversal[i] );
                i+=1;
                while(traversal[i] != '-' && i < traversal.size()){
                    num = num + traversal[i];
                    i += 1;
                }
                TreeNode * newNode = new TreeNode(stoi( num ));
                m[lvl] = newNode;
                addNode(m , lvl , newNode);
                lvl = 0;
            }
        }

        return head;
    }
};