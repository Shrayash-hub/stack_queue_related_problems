class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // so the intution is to maintain a decresing monotonic deque , where index of greater element will be at the front of the deque
        // if we are standing at i then window size will be (i-k-1 to i)
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            // if the index is out of window size pop elements from the front
            if(!dq.empty() && dq.front()<=(i-k)){
                dq.pop_front();
            }
            // pop until we get a greater element in the deque
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            // first window ends at index k-1 , so from there we have elements to insert in ans
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};