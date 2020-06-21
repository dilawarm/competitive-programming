def dp(curr, m, n, rooms, dp_map):
    p = (curr, m)
    if p in dp_map:
        return dp_map[p]
    if m == 0:
        return (0, 0)
    mini, maxi = 1e9, -1
    for i in range(n):
        nxt = dp(i, m-1, n, rooms, dp_map)
        mini = min(mini, nxt[1] + rooms[curr][i])
        maxi = max(maxi, nxt[0] + rooms[curr][i])
    dp_map[p] = (maxi, mini)
    return dp_map[p]

if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break
        rooms = []
        for _ in range(n):
            room = [int(x) for x in input().split()]
            rooms.append(room)
        m = int(input())
        dp_map = {}
        ans = dp(0, m, n, rooms, dp_map)
        print(f"{ans[0]} {ans[1]}")