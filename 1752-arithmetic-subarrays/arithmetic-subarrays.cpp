class Solution {
public:
    bool solve(vector<int> & temp,int left,int right)
    {
        // vector<int> a(begin(temp)+left,begin(temp)+right);
        vector<int> a;
        for(int i=left;i<=right;i++)
        {
            a.push_back(temp[i]);
        }
        sort(begin(a),end(a));
        int diff=a[1]-a[0];
        for(int i=1;i<a.size();i++)
        {
            if(a[i]-a[i-1]!=diff)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
            // vector<int> temp;
            // temp=substr(l[i],r[i]-l[i]+1);
            if(solve(nums,l[i],r[i]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};