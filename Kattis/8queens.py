def main():
    a, b = [False]*15, [False]*15
    c, d = [False]*8, [False]*8

    q = 0
    for i in range(8):
        for j in range(8):
            pos = input()
            while (pos != "*" and pos != "."):
                pos = input()

            if pos == "*":
                q += 1

                if a[j-i+7] or b[i+j] or c[i] or d[j]:
                    return "invalid"
                    
                a[j-i+7] = True
                b[i+j] = True
                c[i] = True
                d[j] = True
    
    if q == 8:
        return "valid"
    else:
        return "invalid"

if __name__ == "__main__":
    print(main())