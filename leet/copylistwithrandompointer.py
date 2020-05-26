class Solution:
    def __init__(self):
        self.clones = {}
    
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        if head in self.clones:
            return self.clones[head]
        node = Node(head.val, None, None)
        self.clones[head] = node
        node.next = self.copyRandomList(head.next)
        node.random = self.copyRandomList(head.random)
        return node