class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        // to make the digit smallest number , we have to put all the smaller values at front , basically we have to get rid of larger values
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // if k is left , so remove the last k values to make number smallest
        while(k>0){
            st.pop(); 
            k--;
        }
        // if stack is empty that means we removed all the elements 
        if(st.empty()) return "0";

        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        // string will have the leading zeros , we have to remove those
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }

        reverse(ans.begin(),ans.end());
        // what if ans have "000000" we have to return zero
        if(ans.empty()) return "0";
        return ans;
    }
};