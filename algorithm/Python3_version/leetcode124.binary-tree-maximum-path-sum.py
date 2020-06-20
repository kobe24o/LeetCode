class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.maxsum = float('-inf')
        def dfs(root):
            if not root:
                return 0
            l = dfs(root.left)
            r = dfs(root.right)
            v = root.val
            curmax = v
            if l>0:
                curmax += l
            if r>0:
                curmax += r
            self.maxsum = max(curmax, self.maxsum)
            return max(v, max(v+l, v+r))
        dfs(root)
        return self.maxsum