class Solution {
public:
    bool queryString(string s, int n) {
        set<int> st;
        if(s.size()==1){
            if(s[0]=='1')return true;
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
            string temp;
            for(int j=i+1;(j<s.size() && j<i+32);j++)
            {
                temp.push_back(s[j]);
                st.insert(stoi(temp,nullptr,2));
            }
        }
        int cnt=1;
        for(auto it:st){
            cout<<it<<" ";
            if(cnt==it)cnt++;
        }
        if(cnt>n)return true;
        return false;
    }
};