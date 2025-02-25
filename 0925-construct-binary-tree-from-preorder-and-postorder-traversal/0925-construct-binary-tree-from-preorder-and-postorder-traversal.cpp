class Solution {
public:

    int find_index(int & num , vector<int>& postorder){
        auto it = find(postorder.begin() , postorder.end() , num);
        return distance(postorder.begin() , it);
    }

    int find_parent(int &num, map<int, int> &m, int &ind) {
        int mini = INT_MAX, parent = -1;
        for (auto &i : m) {
            if (i.second > ind && i.second < mini) {
                mini = i.second;
                parent = i.first;
            }
        }
        return parent;
    }


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       map<int , int> m;
       unordered_map<int , TreeNode*> node;

       int head = preorder[0];
       TreeNode * newNode = new TreeNode(head);
       node[head] = newNode;

       m[head] = postorder.size() - 1;

       for(int i = 1 ; i < preorder.size() ; i++){
            int num = preorder[i];
            TreeNode * newNode = new TreeNode(num);

            int ind = find_index(num , postorder);
            m[num] = ind;
            node[num] = newNode;

            int parent = find_parent(num , m , ind);

            if(!node[parent] -> left) node[parent] -> left = node[num];
            else node[parent] -> right = node[num];

       }
       return node[head];
    }


};