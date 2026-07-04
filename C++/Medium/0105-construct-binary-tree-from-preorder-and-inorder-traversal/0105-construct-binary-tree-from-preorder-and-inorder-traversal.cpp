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

    TreeNode* finder(int& idx,int st,int end,vector<int>& preorder,vector<int>& inorder){
        if(st > end)
            return NULL;

        int rootVal=preorder[idx];
        int i;
        for(i=st;i <= end;i++){
            if(inorder[i]==rootVal)
                break;
        }
        idx++;

        TreeNode* root=new TreeNode(rootVal);

        root->left=finder(idx,st,i-1,preorder,inorder);
        root->right=finder(idx,i+1,end,preorder,inorder);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;

        return finder(idx,0,n-1,preorder,inorder);
    }
};