class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int ele1=st.top();
                st.pop();
                int ele2=st.top();
                st.pop();
                int ans;
                if(tokens[i]=="+"){
                    ans=ele2+ele1;
                }
                else if(tokens[i]=="-")
                {
                    ans=ele2-ele1;
                }
                else if(tokens[i]=="*")
                {
                    ans=ele2*ele1;
                }
                else{
                    ans=ele2/ele1;
                }
                st.push(ans);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};