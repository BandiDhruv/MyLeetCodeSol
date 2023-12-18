class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        // unordered_map<string,int> vis;
        // for(int i=0;i<wordList.size();i++)
        // {
        //     vis[wordList[i]]=0;
        // }
        // int ans=INT_MAX;
        unordered_set<string> st(wordList.begin(),wordList.end());
        while(!q.empty())
        {
            string temp=q.front().first;
            int l=q.front().second;
            // vis[temp]=1;
            st.erase(temp);
            q.pop();
            if(temp==endWord)
                return l;
            for(int i=0;i<temp.size();i++)
            {
                string h=temp;
                for(char j='a';j<='z';j++)
                {
                    if(temp[i]==j)continue;
                    temp[i]=j;
                    // cout<<temp[i]<<"  "<<temp<<"   ";
                    if(st.find(temp)!=st.end() /*&& vis[temp]!=1*/)
                    {
                        // cout<<temp<<"  ";
                        q.push({temp,l+1});
                    }
                    temp=h;
                }
                // cout<<endl;
            }
        }
        return 0;
    }
};