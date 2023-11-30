class Solution {
public:
    // int solve(int n,int &ans)
    // {
    //     if(n==0)
    //         return ans;
    //     for(int i=0;i<)
    // }
    int minimumOneBitOperations(int n) {
        if(n==0)
            return 0;
        vector<long long > temp(31,0);
        temp[0]=1;
        for(int i=1;i<=30;i++)
        {
            temp[i]=2*temp[i-1]+1;
        }
        int sign=1,ans=0;
        for(int i=30;i>=0;i--)
        {
            int setbit=((1<<i)&n);
            if(setbit==0)
                continue;
            if(sign>0)
                ans+=temp[i];
            else
                ans-=temp[i];
            sign*=-1;
        }
        return ans;
    }
};