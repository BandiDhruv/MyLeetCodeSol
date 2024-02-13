class Solution {
public:
    bool isB(string &a)
    {
        int i=0,j=a.size()-1;
        while(i<j)
        {
            if(a[i]!=a[j])return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &i:words)
        {
            if(isB(i))
            {
                return i;
            }
        }
        return "";
    }
};