class Solution:
    def check(self, nums: List[int]) -> bool:
        ans = 0
        for i in range(1 , len(nums)):
            if(nums[i - 1] > nums[i]):
                ans += 1
        
        
        if nums[-1] > nums[0]:
            ans += 1

        return ans <= 1
        