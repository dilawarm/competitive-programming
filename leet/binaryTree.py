class Node:
    def __init__(self, data: int):
        self.left = None
        self.right = None
        self.data = data
    
    def insert(self, data: int) -> None:
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        
        else:
            self.data = data

    def inorder(self) -> None:
        if self.left:
            self.left.inorder()
        print(self.data)
        if self.right:
            self.right.inorder()
    
    def preorder(self) -> None:
        print(self.data)
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()
    
    def postorder(self) -> None:
        if self.left:
            self.left.postorder()
        if self.right:
            self.right.postorder()
        print(self.data)
    
def siblings(root, a, b) -> bool:
    if root is None:
        return False
    return ((root.left == a and root.right == b) or (root.left == b and root.right == a) or siblings(root.left, a, b) or siblings(root.right, a, b))

def level(root, a, l) -> int:
    if root is None:
        return 0
    if root == a:
        return l
    l = level(root.left, a, l+1)
    if l != 0:
        return l
    l = level(root.right, a, l+1)

def cousins(root, a, b) -> bool:
    return level(root, a, 1) == level(root, b, 1) and not siblings(root, a, b)

if __name__ == "__main__":
    root = Node(27)
    root.insert(14)
    root.insert(35)
    root.insert(10)
    root.insert(19)
    root.insert(31)
    root.insert(42)
    print(cousins(root, root.left.right, root.right.left))