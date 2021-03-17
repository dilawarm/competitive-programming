def main():
    n = int(input())
    a = input().split()

    for i in range(n - 1):
        if len(a[i]) == len(a[i + 1]):
            num1 = "9" + a[i][1:]
            num2 = "1" + a[i + 1][1:] if len(a[i]) > 1 else "0"

            if int(num1) > int(a[i + 1]):
                a[i] = num1
                print(" ".join(a))
                return

            if int(a[i]) > int(num2):
                a[i + 1] = num2
                print(" ".join(a))
                return

    print("impossible")
    return


if __name__ == "__main__":
    main()