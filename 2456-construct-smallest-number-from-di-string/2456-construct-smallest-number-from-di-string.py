class Solution:
    def smallestNumber(self, pattern: str) -> str:
        res = ['1']
        l = 0
        c = 2
        for i in range(len(pattern)):
            if pattern[i] == 'I':
                res.append(str(c))
                c+=1
                l = len(res) - 1
            else:
                res.insert(l , str(c))
                c+=1
        return "".join(res)


            
        
        