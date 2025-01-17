class Solution {
public:
    void sortColors(vector<int>& nums) {
        int two=nums.size()-1;
        int zero = 0;
        int i = 0;

        while(i<=two){

            if(nums[i]==0){
                int temp=nums[i];
                nums[i]=nums[zero];
                nums[zero]=temp;
                zero+=1;
                i+=1;
            }

            else if(nums[i]==1) i+=1;

            else{
                int temp=nums[i];
                nums[i]=nums[two];
                nums[two]=temp;
                two-=1;
            }
        }

    }
};