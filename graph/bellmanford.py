def bellmanford(graph: [[int]], start: int, end: int, pred: [int], dist: [int]) -> bool:
    dist[start] = 0
    for _ in range(len(graph)-1):
        for v in range(len(graph)):
            for t in graph[v]:
                u, w = t[0], t[1]
                newDist = dist[v] + w
                if newDist < dist[u]:
                    dist[u] = newDist
                    pred[u] = v
    for _ in range(len(graph)-1):
        for v in range(len(graph)):
            for t in graph[v]:
                u, w = t[0], t[1]
                if dist[v] + w < dist[u]:
                    dist[u] = -float('inf')
    if dist[end] == -float('inf') or dist[end] == float('inf'):
        return False
    return True

def shortestpath(graph: [[int]], start: int, end: int) -> [int]:
    path = []
    pred = [-1 for _ in range(len(graph))]
    dist = [float('inf') for _ in range(len(graph))]
    if not bellmanford(graph, start, end, pred, dist):
        print(dist[end])
        return path
    path.append(end)
    v = end
    while pred[v] != -1:
        path.append(pred[v])
        v = pred[v]
    print(dist[end])
    return path