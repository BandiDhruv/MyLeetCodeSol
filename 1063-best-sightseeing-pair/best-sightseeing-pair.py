class Solution:
    def maxScoreSightseeingPair(self, v: List[int]) -> int:
        @cache
        def solve(i,f):
            if i>= len(v):
                if f==2:
                    return 0
                return -1e7
            op1,op2=0,0
            if f==0:
                op1=v[i]+i+solve(i+1,f+1)
                op2=solve(i+1,f)
            elif f==1:
                op1=v[i]-i+solve(i+1,f+1)
                op2=solve(i+1,f)
            return max(op1,op2)
        return solve(0,0)