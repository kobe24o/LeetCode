class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def build(l,r):
            if l > r:
                return None
            mid = (l+r)>>1
            root = TreeNode(nums[mid])
            root.left = build(l,mid-1)
            root.right = build(mid+1,r)
            return root
        return build(0,len(nums)-1)