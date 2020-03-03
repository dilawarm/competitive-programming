t = int(input())
for _ in range(t):
    x, y = [int(i) for i in input().split(" ")]
    M = max(x, y)
    print((x-y)*(-1)**M+M*M-M+1)