class Solution:
    def reverse(self, s: List[str], left: int, right: int) -> None:
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
    
    def reverseWords(self, s: List[str]) -> None:
        self.reverse(s, 0, len(s)-1)
        
        left = 0
        right = 0
        while left < len(s):
            while right < len(s) and s[right] != " ":
                right += 1
            
            self.reverse(s, left, right-1)
            
            left = right + 1
            right += 1