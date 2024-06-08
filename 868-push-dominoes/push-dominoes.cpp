class Solution {
public:
    string pushDominoes(string d) {
        queue<pair<char,int>> q;
        for(int i=0;i<d.size();i++){
            if(d[i]=='L' || d[i]=='R')q.push({d[i],i});
        }
        while(!q.empty()){
            char ch=q.front().first;
            int idx=q.front().second;
            q.pop();
            if(ch=='L'){
                if(idx>0 && d[idx-1]=='.'){
                    q.push({'L',idx-1});
                    d[idx-1]='L';
                }
            }
            else if(ch=='R'){
                if(idx<d.size()-1 && d[idx+1]=='.'){
                    if(idx+2<d.size() && d[idx+2]=='L')q.pop();
                    else{
                        q.push({'R',idx+1});
                        d[idx+1]='R';
                    }
                }
            }
        }
        return d;
    }
};