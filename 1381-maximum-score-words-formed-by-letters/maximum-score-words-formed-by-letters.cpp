class Solution {
public:
    int calcScore(string word,map<char,pair<int,int>>&mp){
        int score=0;
        for(auto it:word){
            if(mp.find(it)==mp.end())
                return INT_MIN;
            score+=mp[it].second;
            mp[it].first--;
            if(mp[it].first==0)mp.erase(it);
        }
        return score;
    }
    void solve(vector<vector<string>>&subset,vector<string>&words,int i,vector<string>&temp){
        if(i>=words.size()){subset.push_back(temp);return ;}
        temp.push_back(words[i]);
        solve(subset,words,i+1,temp);
        temp.pop_back();
        solve(subset,words,i+1,temp);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        int ans=-1e8;
        vector<vector<string>> subset;
        vector<string> temp;
        solve(subset,words,0,temp);
        // for(auto it:subset){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto it:subset){
            map<char,pair<int,int>> mp;
            for(auto it:letters){
                if(mp.find(it)==mp.end()){
                    mp[it]={1,score[it-'a']};
                }
                else{
                    int cnt=mp[it].first;
                    mp[it]={cnt+1,score[it-'a']};
                }
            }
            long long take=0;
            for(auto i:it){
                take+=calcScore(i,mp);
            }
            ans=max(ans,(int)take);
        }
        return ans==-1e8?0:ans;
    }
};