class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i, j, star, tmp = 0, 0, -1, -1
        while i < len(s):
            if j < len(p) and (p[j] == s[i] or p[j] == '?'):
                i += 1
                j += 1
            elif j < len(p) and p[j] == '*':
                star = j
                tmp = i
                j += 1
            elif star == -1:
                return False
            else:
                j = star + 1
                i = tmp + 1
                tmp = i
        return all(x == '*' for x in p[j:])