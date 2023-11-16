class Solution {
public:
    void solve(vector<int>&lps,string a)
    {
        int i=0,j=1;
        while(j<a.length())
        {
            if(a[i]==a[j]){
                i++;
                lps[j]=i;
                j++;
            }
            else{
                if(i==0)
                    j++;
                else
                    i=lps[i-1];
            }
        }
    }
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        string a =s+ '#'+t;
        vector<int>temp(a.length(),0);
        solve(temp,a);
        int len=temp[a.length()-1];
        string temporary=s.substr(len);
        reverse(temporary.begin(),temporary.end());
        return temporary+s;
    }
};