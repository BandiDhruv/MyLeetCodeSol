class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        long long int ans=0;
        int times=piles.size()/3;
        for(int i=1,j=0;j<times;i+=2,j++)
        {
            ans+=piles[i];
        }
        return ans;
    }
};