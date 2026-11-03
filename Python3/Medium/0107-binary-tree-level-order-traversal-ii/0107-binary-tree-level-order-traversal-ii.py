# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode | None) -> list[list[int]]:
        ans=[]
        if not root:
            return ans

        qu=deque([root])

        while qu:
            level=len(qu)
            temp=[]
            for i in range(level):
                nod=qu.popleft()

                temp.append(nod.val)

                if nod.left:
                    qu.append(nod.left)

                if nod.right:
                    qu.append(nod.right)

            ans.append(temp)

        ans.reverse()
        return ans