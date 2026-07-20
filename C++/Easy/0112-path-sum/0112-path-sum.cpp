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
    bool inOrder(TreeNode* root,int sum,int& targetSum){
        if(! root)
            return false;

        sum += root->val;

        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum)
                return true;

            return false;
        }

        bool leftTree=inOrder(root->left,sum,targetSum);
        bool rightTree=inOrder(root->right,sum,targetSum);

        return leftTree || rightTree;        
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;

        return inOrder(root,sum,targetSum);
    }
};