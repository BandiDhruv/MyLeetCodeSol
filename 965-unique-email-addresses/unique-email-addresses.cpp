class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<pair<string,string>> ans;
        
        for(int i=0;i<emails.size();i++){
            string temp="";
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j]=='@' || emails[i][j]=='+')
                    break;
                if(emails[i][j]!='.')
                    temp.push_back(emails[i][j]);
            }
            int j=0;
            for(;j<emails[i].size();j++){
                if(emails[i][j]=='@')break;
            }
            string domain=emails[i].substr(j);
            cout<<domain<<" "<<temp<<endl;
            ans.insert({domain,temp});
        }
        return ans.size();
    }
};