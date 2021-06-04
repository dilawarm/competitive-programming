t = int(input())
for i in range(t):
    letter = "A"
    n = int(input())
    s = input()
    sus = False
    while letter != chr(ord("Z")+1):
        start = -1
        end = n
        for j in range(n):
            if s[j] == letter:
                start = j
                break
        if start == -1:
            letter = chr(ord(letter) + 1)
            continue
        for j in range(n-1, -1, -1):
            if s[j] == letter:
                end = j
                break
        new_s = s[start+1:end]
        for k in range(len(new_s)):
            if new_s[k] != letter:
                print("NO")
                sus = True
                break
        if sus:
            break
        letter = chr(ord(letter) + 1)
    if not sus:
        print("YES")
