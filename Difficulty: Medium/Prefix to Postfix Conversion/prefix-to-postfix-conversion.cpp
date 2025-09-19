// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        // it is exactly similar to the prefix to infix , but here the converted string will be 
        // top1 + top2 + operator
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
                string converted =  s1 + s2  + s[i] ;
                st.push(converted);
            }
            i--;
        }
        
        return st.top();
    }
};