class Solution:
    def insert(self, head: ListNode, val: int) -> ListNode:
        node = ListNode(val)
        node.next = head
        head = node
        return head
    
    def toNum(self, head: ListNode) -> int:
        curr = head
        num = 0
        while curr != None:
            num = num*10 + curr.val
            curr = curr.next
        return num
    
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num = str(self.toNum(l1) + self.toNum(l2))
        head = None
        for i in range(len(num)-1, -1, -1):
            head = self.insert(head, int(num[i]))
        return head