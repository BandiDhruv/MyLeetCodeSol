class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        // vector<int> l(prices.size()),r(prices.size());
        // l[0]=prices[0];
        // r[prices.size()-1]=prices[prices.size()-1];
        // for(int i=1;i<prices.size();i++)l[i]=min(l[i-1],prices[i]);
        // for(int i=prices.size()-2;i>=0;i--)r[i]=max(r[i+1],prices[i]);
        // for(int i=0;i<prices.size()-1;i++)
        // {
        //     ans=max(ans,r[i]-l[i]);
        // }
        int minprofit=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<minprofit)
                minprofit=prices[i];
            else ans=max(ans,prices[i]-minprofit);
        }
        return ans<0?0:ans;

    }
};