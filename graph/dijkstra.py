from queue import PriorityQueue

def dijkstra(graph: [[int]], start: int, end: int, pred: [int], dist: [int]) -> bool:
    visited = [False for _ in range(len(graph))]
    dist[start] = 0
    pq = PriorityQueue()
    pq.put((0, start))
    while not pq.empty():
        t = pq.get()
        w, v = t[0], t[1]
        visited[v] = True
        if w > dist[v]:
            continue
        for t in graph[v]:
            u, w = t[0], t[1]
            if visited[u]:
                continue
            newDist = dist[v] + w
            if newDist < dist[u]:
                dist[u] = newDist
                pred[u] = v
                pq.put((newDist, u))
        if v == end:
            return True
    return False

def shortestpath(graph: [[int]], start: int, end: int) -> [int]:
    path = []
    pred = [-1 for _ in range(len(graph))]
    dist = [float('inf') for _ in range(len(graph))]
    if not dijkstra(graph, start, end, pred, dist):
        print(dist[end])
        return path
    path.append(end)
    v = end
    while pred[v] != -1:
        path.append(pred[v])
        v = pred[v]
    print(dist[end])
    return path 
