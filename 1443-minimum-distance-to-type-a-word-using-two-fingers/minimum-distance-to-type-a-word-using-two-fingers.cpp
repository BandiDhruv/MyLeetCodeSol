class Solution {
public:
    int solve(string &word,int f1,int f2,int i,unordered_map<char,pair<int,int>>& mp,vector<vector<vector<int>>> &dp){
        if(i>=word.size())
            return 0;
        if(f1!=-1 && f2!=-1 && dp[i][f1][f2]!=-1)return dp[i][f1][f2];
        int ans=1e9;
        if(f1==-1 && f2==-1){
            ans=min(ans,min(solve(word,word[i]-'A',f2,i+1,mp,dp),solve(word,f1,word[i]-'A',i+1,mp,dp)));
        }
        if(f1==-1 && f2!=-1){
            int diff=abs(mp[word[i]].first-mp[f2+'A'].first)+abs(mp[word[i]].second-mp[f2+'A'].second);
            ans=min(ans,min(diff+solve(word,f1,word[i]-'A',i+1,mp,dp),solve(word,word[i]-'A',f2,i+1,mp,dp)));
        }
        if(f2==-1 && f1!=-1){
            int diff=abs(mp[word[i]].first-mp['A'+f1].first)+abs(mp[word[i]].second-mp[f1+'A'].second);
            ans=min(ans,min(diff+solve(word,word[i]-'A',f2,i+1,mp,dp),solve(word,f1,word[i]-'A',i+1,mp,dp)));
        }
        if(f1!=-1 && f2!=-1){
            int diff1=abs(mp[word[i]].first-mp[f1+'A'].first)+abs(mp[word[i]].second-mp[f1+'A'].second);
            int diff2=abs(mp[word[i]].first-mp[f2+'A'].first)+abs(mp[word[i]].second-mp[f2+'A'].second);
            ans=min(ans,min(diff1+solve(word,word[i]-'A',f2,i+1,mp,dp),diff2+solve(word,f1,word[i]-'A',i+1,mp,dp)));
        }
        if(f1!=-1 && f2!=-1)
            dp[i][f1][f2]=ans;
        return ans;
    }
    int minimumDistance(string word) {
        unordered_map<char,pair<int,int>> mp;
        mp['A']={0,0};mp['G']={1,0};mp['M']={2,0};mp['S']={3,0};mp['Y']={4,0};
        mp['B']={0,1};mp['H']={1,1};mp['N']={2,1};mp['T']={3,1};mp['Z']={4,1};
        mp['C']={0,2};mp['I']={1,2};mp['O']={2,2};mp['U']={3,2};
        mp['D']={0,3};mp['J']={1,3};mp['P']={2,3};mp['V']={3,3};
        mp['E']={0,4};mp['K']={1,4};mp['Q']={2,4};mp['W']={3,4};
        mp['F']={0,5};mp['L']={1,5};mp['R']={2,5};mp['X']={3,5};
        int n=word.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(26,vector<int>(26,-1)));
        return solve(word,-1,-1,0,mp,dp);
    }
};