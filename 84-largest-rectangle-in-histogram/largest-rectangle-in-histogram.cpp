class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we can increase the width until we encounter a smaller bar , that means we have look for next smaller and previous smaller element
        // we will be maintaining a monotonix increasing stack
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        // calculating nse and pse is going to lot of space and time,so we will be calculating it in a single traversal , by doing some manipulations
        for(int i=0;i<n;i++){
            // as we encounter a smaller bar , its going to become the nse for top element , then we will pop that element and now new top will become the previous smaller element for that popped element , that how we get to know about both nse and pse of a element
            while(!st.empty() && heights[i]<heights[st.top()]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()? -1:st.top();
                maxArea = max(maxArea,heights[element] *(nse-pse-1));
            }
            st.push(i);
        }
        // if stack is still not empty after all calculations that means remaining elements dont have any nse , so we will assume it n 
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1:st.top();
            maxArea = max(maxArea,heights[element] *(nse-pse-1));
        }
        return maxArea;
    }
};