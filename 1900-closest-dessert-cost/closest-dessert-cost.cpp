class Solution {
public:
    vector<int> temp;
    void util(int i,vector<int>& TC,int ssf,int T)
    {
        if(i==(int)TC.size())
        {
            temp.push_back(ssf);
            return;
        }
        util(i+1,TC,ssf,T);
        util(i+1,TC,ssf+TC[i],T);
        util(i+1,TC,ssf+2*TC[i],T);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        util(0,toppingCosts,0,target);
        for(int i=0;i<baseCosts.size();i++)
        {
            int x=baseCosts[i];
            for(int j=0;j<temp.size();j++)
            {
                int y=temp[j];
                int sum=x+y;
                pq.push({abs(target-sum),sum});
            }
        }
        return pq.top().second;
    }
};