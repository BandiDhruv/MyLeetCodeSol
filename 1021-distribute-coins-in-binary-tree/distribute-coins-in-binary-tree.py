# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__ (self):
        self.ans=0
    def solve(self,root:Optional[TreeNode]) -> int:
        if root==None:return 0
        left=self.solve(root.left)
        right=self.solve(root.right)
        self.ans+=abs(left)+abs(right)
        return left+right+root.val-1
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        self.ans=0
        p=self.solve(root)
        return self.ans