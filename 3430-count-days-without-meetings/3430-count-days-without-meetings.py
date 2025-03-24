class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort(key = lambda x : x[0])
        total_diff = 0

        for i in range(1,len(meetings)):
            if meetings[i][0] <= meetings[i-1][1]:
                if meetings[i][1] < meetings[i-1][1]:
                    meetings[i][1] = meetings[i-1][1]
            
            else:
                total_diff += meetings[i][0] - meetings[i-1][1] - 1
                        
        st = meetings[0][0] - 1
        if st > 0:
            total_diff += st
        
        lt = days - meetings[-1][1] 
        if lt > 0:
            total_diff += lt
        
        return total_diff

        