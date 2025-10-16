/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        if (!root) return {};
        // we need a queue for storing the pair of node and clm
        queue<pair<Node*,int>> q;
        
        // and a map for storing the clm -> value
        map<int,int> mpp;
        
        // similar to the vertical order traversal , just we have to focus on the first encountered node at each clm
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int clm = p.second;
            
            // if we find a node a particular clm , we will check that , ki pheley koi aur node toh nhi mila h same clm pr
            if (mpp.find(clm) == mpp.end()){
                mpp[clm] = node->data;
            }
            if(node->left){
                q.push({node->left,clm-1});
            }
            if(node->right){
                q.push({node->right,clm+1});
            }
        }
        
        vector<int> ans;
        for(auto &it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};