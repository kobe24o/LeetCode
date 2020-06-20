# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.i = 0
        self.can = True
        self.ans = []
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        def dfs(root, voyage):
            if not self.can or not root:
                return
            if root.val == voyage[self.i]:
                self.i += 1
                if root.left and root.left.val == voyage[self.i]:
                    dfs(root.left,voyage)
                    dfs(root.right, voyage)
                elif root.right and root.right.val == voyage[self.i]:
                    if root.left:
                        self.ans.append(root.val)
                    dfs(root.right, voyage)
                    dfs(root.left, voyage)
                elif root.left or root.right:
                    self.can = False
            else:
                self.can = False
        dfs(root, voyage)
        if not self.can:
            return [-1]
        return self.ans