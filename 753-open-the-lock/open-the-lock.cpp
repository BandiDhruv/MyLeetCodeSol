class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        q.push({"0000",0});
        map<string,bool> mp;
        for(auto it:deadends)mp[it]=false;
        if(mp.find("0000")!=mp.end())return -1;
        mp["0000"]=false;
        while(!q.empty()){
            auto s=q.front().first;
            int cnt=q.front().second;
            q.pop();
            // cout<<s<<endl;
            if(s==target)return cnt;
            string t1=s,t2=s,t3=s,t4=s,t5=s,t6=s,t7=s,t8=s;
            if(t1[0]!='9')t1[0]=t1[0]+1;
            else t1[0]='0';
            // cout<<t1;
            if(mp.find(t1)==mp.end()){
                mp[t1]=false;
                q.push({t1,cnt+1});
            }
            if(t2[1]!='9')t2[1]=t2[1]+1;
            else t2[1]='0';
            if(mp.find(t2)==mp.end()){
                mp[t2]=false;
                q.push({t2,cnt+1});
            }if(t3[2]!='9')t3[2]=t3[2]+1;
            else t3[2]='0';
            if(mp.find(t3)==mp.end()){
                mp[t3]=false;
                q.push({t3,cnt+1});
            }if(t4[3]!='9')t4[3]=t4[3]+1;
            else t4[3]='0';
            if(mp.find(t4)==mp.end()){
                mp[t4]=false;
                q.push({t4,cnt+1});
            }
            if(t5[0]!='0')t5[0]=t5[0]-1;
            else t5[0]='9';
            if(mp.find(t5)==mp.end()){
                mp[t5]=false;
                q.push({t5,cnt+1});
            }
            if(t6[1]!='0')t6[1]=t6[1]-1;
            else t6[1]='9';
            if(mp.find(t6)==mp.end()){
                mp[t6]=false;
                q.push({t6,cnt+1});
            }
            if(t7[2]!='0')t7[2]=t7[2]-1;
            else t7[2]='9';
            if(mp.find(t7)==mp.end()){
                mp[t7]=false;
                q.push({t7,cnt+1});
            }
            if(t8[3]!='0')t8[3]=t8[3]-1;
            else t8[3]='9';
            if(mp.find(t8)==mp.end()){
                mp[t8]=false;
                q.push({t8,cnt+1});
            }
        }
        return -1;
    }
};