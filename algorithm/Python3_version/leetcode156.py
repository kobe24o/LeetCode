# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
        if not root or not root.left:
            return root
        l = root.left
        r = root.right
        root.left = None
        root.right = None
        p = self.upsideDownBinaryTree(l)
        l.left = r
        l.right = root
        return p