class Solution {
public:
    bool isValid(string s) {
        stack<int> st; // we will be using stack
        for(int i=0;i<s.size();i++){
            // we will be preserving the opening paran. in the stack
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                st.push(s[i]);
            }
            else{
                // if we encounter a closing paran. and stack is empty at the time , that means we dont have any opening paran. for that closing paran. -> invalid paran.
                if(st.empty()) return false;
                char ch = st.top();
                // if the last opening paran. matches with the encountered closing paran. , we will pop() , last opening paran. , and then continue
                if((s[i]==')' && ch == '(' ) || (s[i]=='}' && ch == '{' ) || (s[i]==']' && ch == '[' )){
                    st.pop();
                }
                else{
                // if not matched then invalid paran.
                    return false;
                }
            }
        }
        // at the end if stack is empty then, we got all the maching paran. nd a valid paren.
        return st.empty();
    }
};