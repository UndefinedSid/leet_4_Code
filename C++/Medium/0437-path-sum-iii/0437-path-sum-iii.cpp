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
    using ll=long long;
    
    int finder(TreeNode* root,ll targetSum,ll sum){
        if(! root)
            return 0;

        sum += root->val;
        int cnt=0;

        if(sum==targetSum){
            cnt++;
        }

        int leftCnt = finder(root->left,targetSum,sum);
        int rightCnt = finder(root->right,targetSum,sum);

        return leftCnt + rightCnt + cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(! root)
            return 0;
            
        return  finder(root,targetSum,0) 
                + pathSum(root->left,targetSum) 
                + pathSum(root->right,targetSum);
    }
};