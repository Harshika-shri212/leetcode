class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l = [0]*n
        pos = 0
        neg = 1
        for i in nums:
            if i > 0:
                l[pos] = i
                pos += 2
            else:
                l[neg] = i
                neg += 2
        return l
        