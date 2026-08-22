/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> finder(int st, int end) {
        if (st > end) {
            return {NULL};
        }

        if (st == end) {
            TreeNode* root = new TreeNode(st);
            return {root};
        }
        vector<TreeNode*> ans;

        for (int i = st; i <= end; i++) {
            vector<TreeNode*> leftBst = finder(st, i - 1);
            vector<TreeNode*> rightBst = finder(i + 1, end);
            for (auto l : leftBst) {
                for (auto r : rightBst) {
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) { 
        return finder(1, n); 
    }
};