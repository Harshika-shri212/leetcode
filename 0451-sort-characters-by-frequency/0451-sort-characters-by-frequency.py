class Solution:
    def frequencySort(self, s: str) -> str:
        d={}
        for i in s:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        
        l = sorted(d , key = lambda x : d[x] , reverse = True)

        res = ''

        for i in l:
            res = res + (i * d[i])
        
        return res
        