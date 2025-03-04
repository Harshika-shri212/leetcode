class Solution:
    def reverseWords(self, s: str) -> str:
        l=s.split()
        st=""
        for i in range(len(l)-1,-1,-1):
            if i!=0:
                st=st+l[i]+" "
            else:
                st=st+l[i]
        return st
        