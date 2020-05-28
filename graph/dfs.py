def dfs(graph: [[int]], v: int, visited: [bool]) -> None:
    if visited[v]:
        return
    visited[v] = True
    for u in range(len(graph)):
        dfs(graph, u, visited)

def totalComponents(graph: [[int]]) -> int:
    visited = [False for _ in range(len(graph))]
    tot = 0
    for v in range(len(graph)):
        if not visited[v]:
            tot += 1        
            dfs(graph, v, visited)
    return tot