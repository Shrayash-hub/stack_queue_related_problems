class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        // similar to next greater element question , here we will be maintaining monotonic stack of increasing order
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1:st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};