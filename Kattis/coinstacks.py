import random

possible = lambda a: sum(a) >= 2 * max(a)

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    if sum(a) % 2 or not possible(a):
        print("no")
    else:
        print("yes")
        while sum(a):
            i, j = random.sample(range(n), 2)
            a[i] -= 1
            a[j] -= 1
            if a[i] >= 0 and a[j] >= 0 and possible(a):
                print(f"{i+1} {j+1}")
            else:
                a[i] += 1
                a[j] += 1