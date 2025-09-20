class Solution {
public:
    int trap(vector<int>& height) {
      // two pointer approch we can use here
      // amount of water stored is min(maxleft,maxright)-height[i]-> that means we need to process shorter one 
      int n = height.size();  
      int left = 0;
      int right = n-1;
      int total = 0;
      int leftmax = 0;
      int rightmax = 0;
      while(left<=right){
        // if left will be shorter we will move left pointer 
        if(height[left]<height[right]){
            if(leftmax>height[left]){
                total+= (leftmax-height[left]);
            }
            else{
                leftmax = height[left];
            }
            left++;
        }
        // and if right will be shorter we will move right pointer
        else{
            if(rightmax>height[right]){
                total = total + (rightmax-height[right]);
            }
            else{
                rightmax = height[right];
            }
            right--;
        }
      } 
      return total; 
    }
};