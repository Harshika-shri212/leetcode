class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int voter=nums[0];
        int vote_count=1;

        for(int i=1;i<nums.size();i++){
            if(voter==nums[i]) vote_count+=1;
            else vote_count-=1;

            if(vote_count==0){
                voter=nums[i];
                vote_count=1;
            }
    
        }
        return voter;
    }
};