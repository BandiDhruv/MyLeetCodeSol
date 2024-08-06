class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st;
        for(auto it:wordList){
            st.insert(it);
        }
        q.push({beginWord,1});
        set<string> vis;
        while(!q.empty()){
            auto temp=q.front().first;
            int cnt=q.front().second;
            vis.insert(temp);
            q.pop();
            if(temp==endWord){
                return cnt;
            }
            for(int i=0;i<temp.size();i++){
                string ori=temp;
                for(char ch='a';ch<='z';ch++){
                    ori[i]=ch;
                    if(st.find(ori)!=st.end() && vis.find(ori)==vis.end()){
                        q.push({ori,cnt+1});
                    }
                }
            }
        }    
        return 0;
    }
};