/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void markParent(Node* root,unordered_map<Node*, Node*> &parent){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    Node* findTarget(Node* root, int target) {
        if (!root) return NULL;
        if (root->data == target) return root;

        Node* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }
    
    
    int minTime(Node* root, int target) {
        // code here
        if (!root) return 0;

        unordered_map<Node*, Node*> parent;
        markParent(root, parent);

        Node* targetNode = findTarget(root, target);
        if (!targetNode) return 0;

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool burnedThisLevel = false;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    burnedThisLevel = true;
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !visited[node->right]) {
                    burnedThisLevel = true;
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if (parent[node] && !visited[parent[node]]) {
                    burnedThisLevel = true;
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }

        if (burnedThisLevel) time++;
        }

        return time;
    }
};