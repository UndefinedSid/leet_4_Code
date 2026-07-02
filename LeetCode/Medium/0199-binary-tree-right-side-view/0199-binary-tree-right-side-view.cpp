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

   //  BFS (level order traversal) approach -> (recommended for this question)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};

        vector<int> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(! qu.empty()){
            int n=qu.size();
            TreeNode* node=NULL;
           
            while(n--){
                node=qu.front();
                qu.pop();

                if(node->left != NULL)
                    qu.push(node->left);
                
                if(node->right != NULL)
                    qu.push(node->right);
                
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};

/*
// DFS (PreOrder level traversal) approach

class Solution {
public:

    void preOrder(TreeNode* root,int level,vector<int>& ans){
        if(root==NULL)
            return;

        if(level > ans.size())
            ans.push_back(root->val);
        
        preOrder(root->right,level+1,ans);

        preOrder(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level;

        preOrder(root,1,ans);

        return ans;
    }
};

*/
