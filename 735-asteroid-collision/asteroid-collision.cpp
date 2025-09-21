class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        // negative means ast. is moving to the left side and positive means ast. is moving to the right side 
        // obvservation is if left side ast. is moving to the right side and right side ast. is moving to the left side then only collision cna happen
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            bool destroyed = false;
            // collision can occur only when st.top>0 ( moving right) and asteroids[i]<0 (moving left)
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                // there can only be three cases
                // if right one is greater pop() left one and insert right one
                if(st.top()<-asteroids[i]){
                    st.pop();
                    continue;
                }
                // both are equal , both will be destoryed
                else if(st.top()== -asteroids[i]){
                    st.pop();
                    destroyed = true;
                    break;
                }
                // left one is greater ,right one will be destroyed
                else{
                    destroyed = true;
                    break;
                }
            }
            if(destroyed == false){
                st.push(asteroids[i]);
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};