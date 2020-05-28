class Solution:
    def process(self, child: 'Node', prev: 'Node', head: 'Node'):
        if child:
            if prev:
                prev.next= child
            else:
                head = child
            prev = child
        return prev, head
    
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        head = root
        while head:
            prev = None
            curr = head
            head = None
            while curr:
                prev, head = self.process(curr.left, prev, head)
                prev, head = self.process(curr.right, prev, head)
                curr = curr.next
        return root