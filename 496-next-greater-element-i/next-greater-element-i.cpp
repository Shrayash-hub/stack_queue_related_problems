class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mpp;
        vector<int> ans;
        // firstly we are going to find the next greater element of each element of nums2 array and then store it in map , in key value pair , then we will iterate each element of nums1 and find the next greater element by maching the values
        int n = nums1.size();
        int m = nums2.size();
        // next greater element of last element will always be -1
        mpp[nums2[m-1]] = -1;
        st.push(nums2[m-1]);
        for(int i=nums2.size()-2;i>=0;i--){
            // we will pop elements form the stack until we get the greater element, and that going to be the NGE for that element
            while(!st.empty() && nums2[i]>st.top()){
                st.pop();
            }
            // in any case if stack became empty and we didnt got any greater element from it , then NGE will be -1
            if(st.empty()){
                mpp[nums2[i]]=-1;
            }
            else{
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<n;i++){
            auto it = mpp.find(nums1[i]);
            if(it!=mpp.end()){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};