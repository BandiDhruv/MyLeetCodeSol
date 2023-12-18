class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        while(!q.empty())
        {
            string temp=q.front().first;
            int l=q.front().second;
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
                    if(st.find(temp)!=st.end())
                    {
                        q.push({temp,l+1});
                    }
                }
                temp=h;
            }
        }
        return 0;
    }
};