class Solution:
    def __init__(self):
        self.arr = []
    
    def inorder(self, root: TreeNode) -> None:
        if not root:
            return
        if root.left:
            self.inorder(root.left)
        self.arr.append(root.val)
        if root.right:
            self.inorder(root.right)
    
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        self.inorder(root)
        return self.arr