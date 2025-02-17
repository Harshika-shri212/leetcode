class Solution:
    def numTilePossibilities(self, tiles: str) -> int:

        def solve(start, nums, curr, res):
            res.append(curr[:])  # Add a copy of curr to res
            for i in range(start, len(nums)):
                curr.append(nums[i])
                solve(i + 1, nums, curr, res)
                curr.pop()  # Backtrack

        def subsets( nums):
            res = []
            solve(0, nums, [], res)
            return res
        
        sub = subsets(list(tiles))[1:]
        se = set()
        for i in range(len(sub)):
            st = "".join(sub[i])
            per = list(permutations(st))
            for j in per:
                per1 = "".join(j)
                if per1 not in se:
                    se.add(per1)
                
        return len(se)
