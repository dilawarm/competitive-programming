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
    
    def isValidBST(self, root: TreeNode) -> bool:
        self.inorder(root)
        for i in range(len(self.arr)-1):
            if self.arr[i] >= self.arr[i+1]:
                return False
        return True