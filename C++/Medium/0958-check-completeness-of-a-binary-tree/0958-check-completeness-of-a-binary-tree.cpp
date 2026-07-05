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
    int nodeCnt(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + nodeCnt(root->left) + nodeCnt(root->right);
    }

    bool dfs(TreeNode* root, int idx, int& nodes) {
        if (!root)
            return true;

        if(idx > nodes)
            return false;

        if(dfs(root->left,2 * idx,nodes) && dfs(root->right,2 * idx + 1,nodes))
            return true;
        else
            return false;
    }

    bool isCompleteTree(TreeNode* root) {

        /* // BFS Approach

        queue<TreeNode*> qu;
        qu.push(root);
        bool seen = false;

        while (!qu.empty()) {
           TreeNode* node = qu.front();
            qu.pop();

            if (node == NULL)
                seen = true;
            else {
                if (seen)
                    return false;

                qu.push(node->left);
                qu.push(node->right);
            }
        }

        return true;

        */

        // DFS + Nodecount approach

        int nodes = nodeCnt(root);

        int idx = 1;
        return dfs(root, idx, nodes);
    }
};