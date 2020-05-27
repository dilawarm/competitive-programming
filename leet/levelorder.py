class Solution:
    def __init__(self):
        self.arr = []
    
    def preorder(self, root: TreeNode, level=0) -> None:
        if not root:
            return
        if len(self.arr) == level:
            self.arr.append([])
        self.arr[level].append(root.val)
        if root.left:
            self.preorder(root.left, level+1)
        if root.right:
            self.preorder(root.right, level+1)
        
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        self.preorder(root)
        return self.arr