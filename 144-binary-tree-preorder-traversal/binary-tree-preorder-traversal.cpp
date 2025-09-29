/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->val);  // Visit (Root)

            if (curr->right) st.push(curr->right); // push right first
            if (curr->left)  st.push(curr->left);  // then left
            // bcoz stack is a LIFO data structure , left will be proccesed first , and then right 
        }
        return ans;
    }
};