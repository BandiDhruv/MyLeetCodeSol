class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        int n=s.size();
        for(int i=k;i<s.size();i+=k)
        {
            if(s.substr(0,n-i)==s.substr(i,n-i)) return i/k;
        }
        return (n+k-1)/k;
    }
};