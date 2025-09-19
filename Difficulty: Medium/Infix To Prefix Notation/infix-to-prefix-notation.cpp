class Solution {
  public:
    int prio(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='*' || c=='/'){
            return 2;
        }
        else if(c=='-' || c=='+'){
            return 1;
        }
        else{
            return -1;
        }
    }
    string infixToPostfix(string& s) {
        // code here
        int i = 0;
        stack<char> st;
        string ans = "";
        
        while(i<s.size()){
            // when we encounter a operand , dirctly add them to the ans
            if((s[i]>='A' && s[i]<='Z')||
               (s[i]>='a' && s[i]<='z')||
               (s[i]>='0' && s[i]<='9')){
                   ans+=s[i];
               }
               
            // when we encounter a opening bracket directly push it to the stack as it has least priority
            else if(s[i]=='('){
                st.push('(');
            }
            
            // when we encounter a closing bracket , pop() from stack until we get a opening bracket
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            
            // when we encounter a operand push them to the stack , if the last entered operand have the lesser than or equal to the priority the new one
            // except in case of '^' , in its case on stricly greater than priority operand will be popped out
            else{
                while(!st.empty() && st.top()!='(' &&
                        (prio(st.top()) > prio(s[i]) ||
                        (prio(st.top()) == prio(s[i]) && s[i] == '^'))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    string infixToPrefix(string &s) {
        // standard trick is to reverse the infix expression , change '(' to ')' and ')' to '('
        // then convert that infix expression into postfix
        // and then again reverse
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
        }
        string postfix = infixToPostfix(s);
        reverse(postfix.begin(),postfix.end());
        return postfix;
        
    }
};
