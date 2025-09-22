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
    long long sumSubarrayMins(vector<int>& arr) {
        // intution is to find the number of contribution(in how many subarrays that element is minimum) rather than finding all the subarrays
        // find the portions of array in which that element is minimum by left = i- previous smaller element and right = next smaller element - i;
        long long total = 0;
        
        vector<int> PSE = pse(arr);
        vector<int> NSE = nse(arr);

        for(int i=0;i<arr.size();i++){
            long long left = i-PSE[i];
            long long right = NSE[i]-i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }
    vector<int> pge(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector<int> pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                pge[i]=-1;
            }
            else{
                pge[i]=st.top();
            }
            st.push(i);
        }
        return pge;
    }

    vector<int> nge(vector<int> arr){
        stack<int> st;
        int n = arr.size();
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=n;
            }
            else{
                nge[i]=st.top();
            }
            st.push(i);
        }
        return nge;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        // intution is to find the number of contribution(in how many subarrays that element is minimum) rather than finding all the subarrays
        // find the portions of array in which that element is maximum by left = i- previous smaller element and right = next smaller element - i;
        long long total = 0;
       
        vector<int> PGE = pge(arr);
        vector<int> NGE = nge(arr);

        for(int i=0;i<arr.size();i++){
            long left = i-PGE[i];
            long right = NGE[i]-i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 1LL * sumSubarrayMaxs(nums) - 1LL * sumSubarrayMins(nums);
        return ans;
    }
};