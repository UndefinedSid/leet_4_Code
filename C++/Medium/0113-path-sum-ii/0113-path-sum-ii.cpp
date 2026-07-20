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
    vector<vector<int>> ans;

    void finder(TreeNode* root,int& targetSum,int sum,vector<int> temp){
        if(! root)
            return;

        sum += root->val;
        
        temp.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
            }
            return;
        }
        finder(root->left,targetSum,sum,temp);
        finder(root->right,targetSum,sum,temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        int sum=0;
        vector<int> temp;

        finder(root,targetSum,sum,temp);

        return ans;
    }
};