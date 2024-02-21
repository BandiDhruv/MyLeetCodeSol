class Solution {
public:
    // vector<int> solve(vector<int> &nums)
    // {
    //     stack<int> st;
    //     vector<int> ans(nums.size());
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         while(!st.empty() && nums[st.top()]<nums[i])
    //         {
    //             st.pop();
    //         }
    //         if(st.empty())ans[i]=-1;
    //         else ans[i]=st.top();
    //         st.push(i);
    //     }
    //     return ans;
    // }
    string removeKdigits(string num, int k) {
        if(num.size()<=k)return "0";
        stack<char> s;
        for(int i=0;i<num.size();i++)
        {
            if(s.empty())s.push(num[i]);
            else{
                while(!s.empty() && s.top()>num[i] && k>0)
                {
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }
        
        while(k>0){
            cout<<s.top()<<" ";
            s.pop();
            k--;
        }
        string ans;
        if(s.empty())return "0";
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0')
            i++;
        return ans.substr(i)==""?"0":ans.substr(i);
    }
};