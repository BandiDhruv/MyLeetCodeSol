class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int i=0,j=tokens.size()-1;
        if(tokens.size()==0)return 0;
        sort(tokens.begin(),tokens.end());
        int ans=INT_MIN;
        while(i<=j)
        {
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(score>0)
            {
                score--;
                power+=tokens[j];
                j--;
            }
            else return score;
            ans=max(ans,score);
        }
        return ans;
    }
};