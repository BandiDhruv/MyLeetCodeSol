class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=0,left=0,cnt=0,p=maxCost;
        for(int right=0;right<s.size();right++){
            if(maxCost-abs(s[right]-t[right])>=0){
                maxCost-=abs(s[right]-t[right]);
            }else {
                while(left<=right){
                    maxCost+=abs(s[left]-t[left]);
                    left++;
                    if(abs(s[right]-t[right])<=maxCost){right--;break;}
                }
            }
            len=max(right-left+1,len);
        }
        return len;
    }
};