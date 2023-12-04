class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> ans;
        for(int i=0;i<num.size()-2;i++)
        {
            string tm="";
            if(num[i] == num[i+1] && num[i] == num[i+2])
            {
                tm+=num[i];
                tm+=num[i];
                tm+=num[i];
                ans.push_back(tm);
            }   

        }
        sort(ans.rbegin(),ans.rend());
        if(ans.size()!=0)
            return ans[0];
        return "";
    }
};