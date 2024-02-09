class Solution {
public:
    bool to_bool(char x) {
        if (x == 'f') return false;
        return true;
    }
    char to_char(bool x) {
        if (x == 0) return 'f';
        return 't';
    }
    bool parseBoolExpr(string e) {
        stack<char> op;
        stack<char> tf;
        for(auto &i:e)
        {
            if(i=='&'|| i=='|'||i=='!')
            {
                op.push(i);
            }
            else if (i == '(' || i == ')' || i == 't' || i == 'f'){
                if(i==')')
                {
                    if(!op.empty() && !tf.empty())
                    {
                        char open=op.top();
                        op.pop();
                        bool t=to_bool(tf.top());
                        tf.pop();
                        if(open=='&')
                        {
                            while(!tf.empty() && tf.top()!='(')
                            {
                                t=t&to_bool(tf.top());
                                tf.pop();
                            }
                        }
                        else if(open=='|')
                        {
                            while(!tf.empty() && tf.top()!='(')
                            {
                                t=t|to_bool(tf.top());
                                tf.pop();
                            }
                        }
                        else t=!t;
                        if(!tf.empty() && tf.top()=='(')tf.pop();
                        tf.push(to_char(t));
                    }
                }
                else tf.push(i);
            }
            else continue;
        }

        return (!tf.empty() && to_bool(tf.top()));
    }
};