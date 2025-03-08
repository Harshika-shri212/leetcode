class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int op = INT_MAX;
        int w = 0;
        int flag = 0;
        
        for(int i = 0; i <= blocks.size() - k; i++){ 
            w = 0;
            
            for(int j = i; j < i + k; j++){
                if (blocks[j] == 'W') w += 1;
            }
            
            if (w == 0) return 0; 
            
            op = min(op, w);
        }
        
        return op;
    }
};
