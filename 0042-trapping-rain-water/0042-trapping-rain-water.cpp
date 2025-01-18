class Solution {
public:
    int trap(vector<int>& height) {

        vector<int> left_max;
        left_max.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            int lm=fmax(height[i],left_max[i-1]);
            left_max.push_back(lm);
        }

        vector<int> right_max(height.size(),-1);
        right_max[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--){
            int rm=fmax(height[i], right_max[i+1]);
            right_max[i]=rm;
        }

        int water = 0;
        for(int i=0; i<height.size(); i++){
            water+= fmin(left_max[i] , right_max[i]) - height[i];
        }

        return water;
    }
};