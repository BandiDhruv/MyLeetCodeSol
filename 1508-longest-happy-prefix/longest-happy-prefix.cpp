class Solution {
public:
    string longestPrefix(string s) {
        // string temp="";
        // int n=s.length();
        // // int i=0,j=1;
        // vector<string> pre;
        // vector<string> suf;
        // for(int i=1;i<s.length();i++)
        // {
        //     string a=s.substr(0,i);
        //     pre.push_back(a);
        // }
        // for(int i=s.length()-1;i>=0;i--)
        // {
        //     string a=s.substr(i,n-i+1);
        //     suf.push_back(a);
        // }
        // for(int i=0;i<pre.size();i++)
        // {
        //     if(find(suf.begin(),suf.end(),pre[i])!=suf.end())
        //     {
        //         if(pre[i].size()>temp.size())
        //             temp=pre[i];
        //     }
        // }
        // return temp;
        int i=0,j=1;
        vector<int> lps(s.length(),0);
        //THIS LPS APPROACH FROM AANCHAL VIDEO ->https://www.youtube.com/watch?v=sy-jwlCETfw&t=778s
        while(j<s.length())
        {
            if(s[i]==s[j])
            {
                i++;
                lps[j]=i;
                j++;
            }
            else
            {
                if(i==0)
                    j++;
                else
                    i=lps[i-1];
            }
        }
        string ans=s.substr(0,lps[s.length()-1]);
        return ans;
    }
};