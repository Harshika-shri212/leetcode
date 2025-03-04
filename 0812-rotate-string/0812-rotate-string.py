class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        st = ''
        n = len(s)
        m = n
        while m != 0:
            st = s[1:n] + s[0]
            print(st)
            print()
            if st == goal:
                return True
            else:
                s = st
                print(s)
                print()
                st = ''
                m -= 1
        return False; 
        