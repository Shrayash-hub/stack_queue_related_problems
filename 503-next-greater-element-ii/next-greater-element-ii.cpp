class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // idea is to iterate the array 2 time , by doubling the array virtually 
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            // values for i>=n are useless , because eventually they will be overwritten by the value coming in second iterations (i<n)
            if(i<n){
            if(st.empty()) ans[i%n] = -1;
            else ans[i%n] = st.top();
            }
            
            st.push(nums[i%n]);
        }
        return ans;
    }
};