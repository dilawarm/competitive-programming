class Solution:
    def myAtoi(self, str: str) -> int:
        INT_MIN = -2**31
        INT_MAX = (2**31) - 1
        
        atoi = 0
        sign = 1
        i = 0
        while i < len(str) and str[i] == " ":
            i += 1
        
        if i > len(str)-1:
            return atoi
        
        if str[i] == "-":
            sign = -1
            i += 1
        elif str[i] == "+":
            i += 1
        
        while i < len(str) and str[i] >= '0' and str[i] <= '9':
            if atoi > (INT_MAX - (ord(str[i]) - ord('0'))) / 10:
                if sign == 1:
                    return INT_MAX
                else:
                    return INT_MIN
            atoi = atoi*10 + (ord(str[i]) - ord('0'))
            i += 1
        
        return sign*atoi