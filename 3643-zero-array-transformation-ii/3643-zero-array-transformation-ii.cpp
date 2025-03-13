class Solution {
public:
    bool checkWithDiffArray(vector<int> &nums,vector<vector<int>> &queries,int k){
        vector<int> diffArr(nums.size(),0);
       
        for(int i=0;i<=k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=queries[i][2];

            diffArr[l]+=x;
            if(r+1<nums.size())
            diffArr[r+1]-=x;
        }

    
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=diffArr[i];
            diffArr[i]=sum;

            if(nums[i]-diffArr[i]>0){
                return 0;
            }

        }
        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        auto lambda=[](int x){
            return x==0;
        };
        if(all_of(begin(nums),end(nums),lambda)){
            return 0;
        }

        
        int l=0,r=queries.size()-1;
        int mid=0;
        int ans=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(checkWithDiffArray(nums,queries,mid)){
                ans=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;


    }
};