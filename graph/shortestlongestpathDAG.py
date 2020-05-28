def dfs(graph: [[int]], v: int, visited: [bool], topo: [int]) -> None:
    if visited[v]:
        return
    visited[v] = True
    for t in range(len(graph)):
        u = t[0]
        dfs(graph, u, visited)
    topo.append(v)

def toposort(graph: [[int]]) -> [int]:
    topo = []
    visited = [False for _ in range(len(graph))]
    for v in range(len(graph)):
        dfs(graph, v, visited, topo)
    return topo[::-1]

def pathutil(graph: [[int]], start: int, end: int, pred: [int], dist: [int], longest: bool) -> bool:
    topo = toposort(graph)
    dist[start] = 0
    for v in topo:
        if dist[v] != float('inf'):
            for t in graph[v]:
                u = t[0]
                if longest:
                    w = -t[1]
                else:
                    w = t[1]
                newDist = dist[v] + w
                if newDist < dist[u]:
                    dist[u] = newDist
                    pred[u] = v
        if v == end:
            return True
    return False

def shortestlongestpath(graph: [[int]], start: int, end: int, longest: bool) -> [int]:
    path = []
    pred = [-1 for _ in range(len(graph))]
    dist = [float('inf') for _ in range(len(graph))]
    if not pathutil(graph, start, end, pred, dist, longest):
        print(dist[end])
        return path
    path.append(end)
    v = end
    while pred[v] != -1:
        path.append(pred[v])
        v = pred[v]
    if longest:
        print(-dist[end])
    else:
        print(dist[end])
    return path