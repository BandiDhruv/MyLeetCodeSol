class Solution:
    @cache
    def solve(self,i:int,k:int,j:int,f:bool)->int:
        c=0 
        if i>k+1:return 0
        if i==k :c=1
        p1=0
        if f and i!=0:
            p1=self.solve(i-1,k,j,False)
        p2=self.solve(i+pow(2,j),k,j+1,True)
        return p1+p2+c

    def waysToReachStair(self, k: int) -> int:
        return self.solve(1,k,0,True)