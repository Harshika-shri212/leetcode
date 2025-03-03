class Solution:
    def rob(self, nums: List[int]) -> int:
        if(len(nums) == 1 or len(nums) == 2):
            return max(nums)

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = nums[1]
        
        
        for i in range(2 , len(nums) , 1):
            c = max(dp[:i-1])
            dp[i] = c + nums[i]
        return max(dp)

        