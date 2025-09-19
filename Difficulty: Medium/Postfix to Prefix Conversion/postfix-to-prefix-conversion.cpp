// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        // it is exactly similar to postfix to infix , just here converted string will be like
        // operator + top2 + top1
        stack<string> st;
        int i=0;
        while(i<s.size()){
            // directly push an operand into the stack
            if((s[i]>='A' && s[i]<='Z')||
               (s[i]>='a' && s[i]<='z')||
               (s[i]>='0' && s[i]<='9'))
               {
                   st.push(string(1,s[i]));
               }
            // when an operator is encountered , take the last two operands from the stack and put that operator b/w them
            // and then wrap it in braces
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string converted = string(1,s[i]) + s2 + s1;
                st.push(converted);
            }
            i++;
        }
        return st.top();
    }
};