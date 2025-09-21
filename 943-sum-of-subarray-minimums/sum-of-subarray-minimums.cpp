class Solution {
public:
    vector<int> pse(vector<int> arr){
        vector<int> pse(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> nse(vector<int> arr){
        vector<int> nse(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=arr.size();
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // intution is to find the number of contribution(in how many subarrays that element is minimum) rather than finding all the subarrays
        // find the portions of array in which that element is minimum by left = i- previous smaller element and right = next smaller element - i;
        int total = 0;
        int mod = (int)1e9 + 7;
        vector<int> PSE = pse(arr);
        vector<int> NSE = nse(arr);

        for(int i=0;i<arr.size();i++){
            int left = i-PSE[i];
            int right = NSE[i]-i;
            total = ((total + ((1LL*left*right)%mod)*arr[i])%mod)%mod;
        }
        return total;
        
    }
};