// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        // exactly similar to the postfix to infix conversion, but here we will traverse from back
        // and s1 + operand + s2 will be the converted string
        int i =s.size()-1;
        stack<string> st;
        while(i>=0){
            // directly push an operand into the stack
            if((s[i]>='A' && s[i]<='Z')||
               (s[i]>='a' && s[i]<='z')||
               (s[i]>='0' && s[i]<='9'))
               {
                   st.push(string(1,s[i]));
               }
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string converted = '('+ s1 + s[i] + s2 + ')';
                st.push(converted);
            }
            i--;
        }
        
        return st.top();
    }
};