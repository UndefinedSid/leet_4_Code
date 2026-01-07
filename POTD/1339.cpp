/*
PROBLEM -->> 1339 (MEDIUM) -->  Maximum Product of Splitted Binary Tree

Given the root of a binary tree, split the binary tree into two subtrees 
by removing one edge such that the product of the sums of the subtrees is maximized.
Return the maximum product of the sums of the two subtrees. Since the answer may be too large,
return it modulo 10^9 + 7. i.e., 1000000007

Note that you need to maximize the answer before taking the mod and not after taking it.

The number of nodes in the tree is in the range [2, 5 * 10^4].
1 <= Node.val <= 10^4

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
    const int MOD=1e9 + 7;
    long SUM=0;
    long maxProd;

    int finalSum(TreeNode* root){
        if( !root)
            return 0;
    
        int leftSum=finalSum(root->left);
        int rightSum=finalSum(root->right);
        long subTreeSum=root->val + leftSum + rightSum;
        long remainSum=SUM - subTreeSum ;

        maxProd=max(maxProd,subTreeSum * remainSum);

        return subTreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        if( root ==NULL)
        return 0;

        maxProd=0;

        SUM=finalSum(root);

        finalSum(root);

        return maxProd % MOD;
    }
};

/*
1. finalSum(TreeNode* root) function
	◦ This function recursively traverses the entire tree.
	◦ For each node, it:
		▪︎ Recursively computes the sum of the left subtree.
		▪︎ Recursively computes the sum of the right subtree.
		▪︎ Performs constant-time operations (addition, multiplication, max).

2. maxProduct(TreeNode* root) function
	◦ First call: SUM = finalSum(root);
		▪︎ This computes the total sum of the tree → O(n).
	◦ Second call: finalSum(root);
		▪︎ This recomputes subtree sums and updates maxProd → O(n).
*/

// TIME COMPLEXITY --> O(N)
// SPACE COMPLEXITY --> O(N)
