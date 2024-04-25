class Solution:

    def solve(self,s:str,k:int,i:int,c:chr,dp)->int:
        if i>=len(s):
            return 0
        take,nottake=0,0
        if dp[i][ord(c)-ord('a')]!=-1:
            return dp[i][ord(c)-ord('a')]
        if(c=='{' or abs(ord(c)-ord(s[i]))<=k):
            take=1+self.solve(s,k,i+1,s[i],dp)
        nottake=self.solve(s,k,i+1,c,dp)
        dp[i][ord(c)-ord('a')]=max(take,nottake)
        return dp[i][ord(c)-ord('a')]
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)+1
        dp = [[-1] * 27 for _ in range(n + 1)]
        return self.solve(s,k,0,'{',dp)