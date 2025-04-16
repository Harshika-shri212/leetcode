class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        pref = [nums[0]]
        for i in range(1,len(nums)):
            pref.append(pref[-1] + nums[i])
        
        ans = float('-inf')

        for i in range(k):
            ind = i
            cur = float('-inf')
            while ind + k <= len(nums):
                if ind == 0:
                    tot = pref[ind + k - 1]
                else:
                    tot = pref[ind + k - 1] - pref[ind - 1]
                cur = max(tot , cur + tot)
                ans = max(ans , cur)
                ind += k
        
        return ans
        