def convert(n, mod):
    if n < 0:
        return (n % mod) + mod
    else:
        return n % mod

if __name__ == "__main__":
    while True:
        n, tot = [int(x) for x in input().split()]
        if n == 0 and tot == 0:
            break
        for _ in range(tot):
            x, op, y = [x for x in input().split()]
            x, y = convert(int(x), n), convert(int(y), n)
            if op == "+":
                print((x+y)%n)
            elif op == "-":
                print((x-y)%n)
            elif op == "*":
                print((x*y)%n)
            else:
                t, t_n, r, r_n = 0, 1, n, y
                while r_n:
                    q = int(r / r_n)
                    s = t - q*t_n
                    t = t_n
                    t_n = s
                    s = r - q*r_n
                    r = r_n
                    r_n = s
                if r > 1:
                    print(-1)
                else:
                    t = convert(t, n)
                    print((x*t)%n)