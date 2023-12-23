class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;
        stack <pair<int,int>> st;
        st.push({0,0});
        s.insert({0,0});
        for(int i=0;i<path.size();i++)
        {
            auto it=st.top();
            if(path[i]=='S'){
                if(s.find({it.first,it.second-1})!=s.end()) return true;
                s.insert({it.first,it.second-1});
                st.push({it.first,it.second-1});
            }
            else if(path[i]=='N'){
                if(s.find({it.first,it.second+1})!=s.end()) return true;
                s.insert({it.first,it.second+1});
                st.push({it.first,it.second+1});
            }
            else if(path[i]=='E'){
                if(s.find({it.first+1,it.second})!=s.end()) return true;
                s.insert({it.first+1,it.second});
                st.push({it.first+1,it.second});
            }
            else{
                if(s.find({it.first-1,it.second})!=s.end()) return true;
                s.insert({it.first-1,it.second});
                st.push({it.first-1,it.second});
            } 
        }
        return false;
    }
};