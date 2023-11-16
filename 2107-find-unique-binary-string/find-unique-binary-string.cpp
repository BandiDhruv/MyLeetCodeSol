class Solution {
public:
    void solve(string &ans,string temp,vector<string>&nums,int n)
    {
        if(temp.size()==n)
        {
            if(find(nums.begin(),nums.end(),temp)==nums.end())
                ans=temp;
            return;
        }
        solve(ans,temp+"0",nums,n);
        // temp.pop_back();
        solve(ans,temp+"1",nums,n);
        // temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string temp="";
        string ans="";
        solve(ans,temp,nums,nums.size());
        return ans;
    }
};