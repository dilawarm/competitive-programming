def floydwarshall(graph: [[int]], dp: [[int]], next: [[int]]) -> None:
    for k in range(len(graph)):
        for i in range(len(graph)):
            for j in range(len(graph)):
                newDist = dp[i][k] + dp[k][j]
                if newDist < dp[i][j]:
                    dp[i][j] = newDist
                    next[i][j] = next[i][k]
    for k in range(len(graph)):
        for i in range(len(graph)):
            for j in range(len(graph)):
                if dp[i][k] + dp[k][j] < dp[i][j]:
                    dp[i][j] = -float('inf')
                    next[i][j] = -1

def shortestpath(graph: [[int]], start: int, end: int) -> [int]:
    path = []
    dp = [[None for _ in range(len(graph))] for _ in range(len(graph))]
    next = [[None for _ in range(len(graph))] for _ in range(len(graph))]
    floydwarshall(graph, dp, next)
    if dp[start][end] == float('inf'):
        return path
    v = start
    while v != end:
        if v == -1:
            print(float('inf'))
            return []
        path.append(v)
        v = next[v][end]
    if next[v][end] == -1:
        print(float('inf'))
        return []
    path.append(end)
    print(dp[start][end])
    return path