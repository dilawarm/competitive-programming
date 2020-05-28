def dfs(graph: [[int]], v: int, visited: [bool], topo: [int]) -> None:
    if visited[v]:
        return
    visited[v] = True
    for u in range(len(graph)):
        dfs(graph, u, visited)
    topo.append(v)

def toposort(graph: [[int]]) -> [int]:
    topo = []
    visited = [False for _ in range(len(graph))]
    for v in range(len(graph)):
        dfs(graph, v, visited, topo)
    return topo[::-1]