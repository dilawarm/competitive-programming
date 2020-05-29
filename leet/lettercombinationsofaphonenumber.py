class Solution:
    def __init__(self):
        self.phone = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }
        self.combinations = []
    
    def backtracking(self, digits, comb=""):
        if not digits:
            self.combinations.append(comb)
        else:
            for s in self.phone[digits[0]]:
                self.backtracking(digits[1:], comb+s)
            
    def letterCombinations(self, digits: str) -> List[str]:
        if digits:
            self.backtracking(digits)
        return self.combinations