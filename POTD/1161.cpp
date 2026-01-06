/*
PROBLEM -->> 1161 (MEDIUM) -->> Maximum Level Sum of a Binary Tree
TOPICS --> Tree, Depth-First Search, Breadth-First Search ,Binary Tree

Given the root of a binary tree, the level of its root is 1, 
the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

The number of nodes in the tree is in the range [1, 104].
-10^5 <= Node.val <= 10^5

*/

// DFS APPROACH

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
    map<int,int> mp;
    void DFS(TreeNode* root,int level){
        if(! root)
        return;

        mp[level] += root->val;

        DFS(root->left,level+1);
        DFS(root->right,level+1);
    }

    int maxLevelSum(TreeNode* root) {
        mp.clear();
        int maxSum=INT_MIN;
        int ansLevel=0;
        DFS(root,1);

        for(auto &p : mp){
            int level=p.first;
            int sum=p.second;

            if(sum > maxSum){
                maxSum=sum;
                ansLevel=level;
            }
        }
        return ansLevel;
    }
};

// BFS APPROACH

class Solution {
public:

    int maxLevelSum(TreeNode* root) {
      int maxSum=INT_MIN;
      int ansLevel=0;

      queue<TreeNode*> qu;
      qu.push(root);

      int currLevel=1;

    while( ! qu.empty()){
        int n=qu.size();
        int sum=0;

        while(n--){
            TreeNode* temp=qu.front();
            qu.pop();

            sum += temp->val;

            if(temp->left){
                qu.push(temp->left);
            }

            if(temp->right){
                qu.push(temp->right);
            }
        }

        if(sum > maxSum){
            maxSum=sum;
            ansLevel=currLevel;
        }
        currLevel++;

    }
    return ansLevel;

    }
};

// time complexity -->  O(N)
