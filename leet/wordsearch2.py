class Node:
    def __init__(self):
        self.word = None
        self.isWord = False
        self.arr = [None for _ in range(26)]

class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self, word):
        curr = self.root
        for s in word:
            index = ord(s) - ord('a')
            if not curr.arr[index]:
                curr.arr[index] = Node()
            curr = curr.arr[index]
        curr.word = word
        curr.isWord = True
        
class Solution:
    def __init__(self):
        self.result = set()
    
    def backtrack(self, board, c, i, j, result, curr):
        index = ord(c) - ord('a')
        if board[i][j] == "#" or not curr.arr[index]:
            return
        board[i][j] = "#"
        curr = curr.arr[index]
        if curr.isWord:
            self.result.add(curr.word)
        x = [-1, 1, 0, 0]
        y = [0, 0, -1, 1]
        for k in range(len(x)):
            row = i + x[k]
            column = j + y[k]
            if row < 0 or row >= len(board) or column < 0 or column >= len(board[row]):
                continue
            self.backtrack(board, board[row][column], row, column, self.result, curr)
        board[i][j] = c
        
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.insert(word)
        root = trie.root
        for i in range(len(board)):
            for j in range(len(board[i])):
                c = board[i][j]
                if root.arr[ord(c)-ord('a')]:
                    self.backtrack(board, c, i, j, self.result, root)
        return list(self.result)