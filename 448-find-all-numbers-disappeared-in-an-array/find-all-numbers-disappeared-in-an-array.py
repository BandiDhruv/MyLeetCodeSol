class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n=len(nums);
        result=[0]*(n+1);
        for i in nums:
            result[i]+=1;
        ans=[];
        for i in range(1,n+1):
            if(result[i]==0):ans.append(i);
        return ans;