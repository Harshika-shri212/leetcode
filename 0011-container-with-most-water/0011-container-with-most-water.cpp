class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0 , lm = height[0] , rm = height[height.size()-1];
        int left = 0 , right = height.size()-1;

        while(left < right){
            int width = right - left;
            max_area = fmax(max_area , fmin(height[left] , height[right]) * width);
            if ( height[left] < height[right] ) left+=1;
            else right-=1;
      }

      return max_area;
    }
};