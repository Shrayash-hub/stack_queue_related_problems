class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        // here we will be using 2 pointer approch , and the observation that there can be only 1 celebrity
        // among all the persons
        // pointers at two extremes
        if(mat.size()==1) return 0;
        int top = 0;
        int n = mat.size();
        int down = mat.size()-1;
        while(top<down){
            // if top knows down , then top cant be a celebrity
            if(mat[top][down]==1){
                top++;
            }
            // if down knows top , then down cant be a celebrity
            else if(mat[down][top]==1){
                down--;
            }
            // if both knows each other , then both of them are not celebrity
            else{
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        
        // rechecking that , found person is celeb or not , if he/she is a celeb then whole row will be filled with zero
        // and while clm is filled with 1 , except (person, person) clm
        for(int i =0;i<n;i++){
            if (i == top) continue;

            // condition 1: candidate should not know anyone
        if (mat[top][i] == 1) return -1;

        // condition 2: everyone should know candidate
        if (mat[i][top] == 0) return -1;
        }
        return top;
    }
};