class Solution {
public:
    bool solve(vector<int> & temp)
    {
        int maxi=INT_MIN,mini=INT_MAX,n=temp.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,temp[i]);
            mini=min(mini,temp[i]);
            st.insert(temp[i]);
        }
        if((maxi-mini)%(temp.size()-1)!=0)
            return false;
        int diff=(maxi-mini)/(temp.size()-1);
        int curr=mini+diff;
        while(curr<maxi)
        {
            if(st.find(curr)==st.end())
                return false;
            curr+=diff;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
            vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            if(solve(temp))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};