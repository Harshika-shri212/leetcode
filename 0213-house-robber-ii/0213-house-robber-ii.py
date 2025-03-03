class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1 or n == 2 or n == 3:
            return max(nums)

        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = nums[1]

        for i in range(2 , n -1 , 1):
            c = max(dp[:i-1])
            dp[i] = c + nums[i]
        m1 = max(dp)

        for i in range(2 , n  , 1):
            c = max(dp[1 : i-1] , default = 0)
            dp[i] = c + nums[i]
        m2 = max(dp)

        return max(m1 , m2)


        