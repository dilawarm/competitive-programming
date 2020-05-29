class Solution:
    def __init__(self):
        self.clones = {}
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        if node in self.clones:
            return self.clones[node]
        n = Node(node.val, [])
        self.clones[node] = n
        for neighbor in node.neighbors:
            n.neighbors.append(self.cloneGraph(neighbor))
        return n