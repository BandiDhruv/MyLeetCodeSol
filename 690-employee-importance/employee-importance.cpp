/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
//1->(2,3)
    int getImportance(vector<Employee*> e, int id) {
        map<int,vector<int>>mp;
        for(int i=0;i<e.size();i++){
            for(auto it:e[i]->subordinates){
                mp[e[i]->id].push_back(it);
            }
        }
        int ans=0;
        for(int i=0;i<e.size();i++){
            if(e[i]->id==id){
                ans+=e[i]->importance;break;
            }
        }
        queue<int> q;
        q.push(id);
        while(!q.empty())
        {
            int ids=q.front();
            q.pop(); 
            for(auto it:mp[ids]){
                for(int i=0;i<e.size();i++){
                    if(e[i]->id==it){
                        ans+=e[i]->importance;
                        // for(auto k:e[i]->subordinates)
                        // {
                            // cout<<k<<endl;
                            q.push(it);
                        // }
                    }
                }
            }
        }
        return ans;
    }
};