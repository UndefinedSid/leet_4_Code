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
    int cnt=0;

    pair<int,int> dfs(TreeNode* root){
        if(! root)
            return {0,0};

        auto [lhsSum,lhsCnt]=dfs(root->left);
        auto [rhsSum,rhsCnt]=dfs(root->right);

        int currSum=root->val + lhsSum + rhsSum;
        int currCnt=1 + lhsCnt + rhsCnt;

        if(root->val == currSum / currCnt)
            cnt++;

        return {currSum,currCnt}; 
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};