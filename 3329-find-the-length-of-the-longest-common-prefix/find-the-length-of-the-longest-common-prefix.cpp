class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        for(int i=0;i<arr1.size();i++)
        {
            string temp=to_string(arr1[i]);
            for(int j=0;j<=temp.size();j++)
            {
                mp1[temp.substr(0,j)]++;
            }
        }
        for(int i=0;i<arr2.size();i++)
        {
            string temp=to_string(arr2[i]);
            for(int j=0;j<=temp.size();j++)
            {
                mp2[temp.substr(0,j)]++;
            }
        }
        int ans=0;
        for(auto it:mp1)
        {
            string a=it.first;
            int t=a.size();
            if(it.second>0)
            {
                if(mp2.find(a)!=mp2.end())ans=max(ans,t);
            }
        }
        return ans;
    }
};