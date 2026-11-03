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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            int level=qu.size();
            vector<int> temp;
            for(int i=0;i<level;i++){
                TreeNode* nod=qu.front();
                qu.pop();
                temp.push_back(nod->val);

                if(nod->left)
                    qu.push(nod->left);

                if(nod->right)
                    qu.push(nod->right);
            }
           ans.push_back(temp);

        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};