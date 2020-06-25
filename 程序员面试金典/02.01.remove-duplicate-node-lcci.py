class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        s = set()
        s.add(head.val)
        prev = head
        cur = head.next
        while cur:
            if cur.val not in s:
                s.add(cur.val)
                prev = cur
            else:
                prev.next = cur.next
            cur = cur.next
        return head