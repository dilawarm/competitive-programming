class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        seen = set()
        for letter in s:
            if letter in seen:
                seen.remove(letter)
            else:
                seen.add(letter)
        return len(seen) <= 1