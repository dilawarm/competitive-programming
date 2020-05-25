class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        curr = head
        first = None
        while curr != None:
            node = curr.next
            curr.next = first
            first = curr
            curr = node
        return first