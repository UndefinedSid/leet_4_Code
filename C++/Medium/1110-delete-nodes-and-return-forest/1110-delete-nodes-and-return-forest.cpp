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

    TreeNode* finder(TreeNode* root,vector<TreeNode*>& ans, unordered_set<int>& st){
        if(root==NULL)
            return NULL;
        
        root->left=finder(root->left,ans,st);
        root->right=finder(root->right,ans,st);

        if(st.count(root->val)){
            if(root->left != NULL)
                ans.push_back(root->left);

            if(root->right != NULL)
                ans.push_back(root->right);

            return NULL;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;

        for(int value : to_delete)
            st.insert(value);

        finder(root,ans,st);

        if(!st.count(root->val)){
            ans.push_back(root);
        }

        return ans;
    }
};