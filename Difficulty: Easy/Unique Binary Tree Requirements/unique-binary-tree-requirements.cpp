// User function Template for C++

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        // it concludes a simple logic that , if we have given the inorder and any other traversal , then we 
        // can make unique binary tree, else we cannot make unique binary tree
        if(a==1 && b==3) return false;
        else if(a==3 && b==1) return false;
        else if(a==b) return false;
        return true;
    }
};