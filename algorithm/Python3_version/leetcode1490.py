"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        if not root:
            return root
        r = Node(root.val)
        for c in root.children:
            child = self.cloneTree(c)
            r.children.append(child)
        return r