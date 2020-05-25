from queue import PriorityQueue

class Priority(object):
    def __init__(self, priority, data):
        self.priority = priority
        self.data = data
    
    def __lt__(self, other):
        return self.priority < other.priority

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        pq = PriorityQueue()
        head = ListNode()
        curr = head
        
        for h in lists:
            if h:
                pq.put(Priority(h.val, h))
        
        while not pq.empty():
            t = pq.get()
            val, node = t.priority, t.data
            curr.next = ListNode(val)
            curr = curr.next
            node = node.next
            if node:
                pq.put(Priority(node.val, node))
        
        return head.next