from queue import Queue

def bfs(graph: [[int]], start: int, end: int, pred: [int], dist: [int]) -> bool:
    visited = [False for _ in range(len(graph))]
    visited[start] = True
    dist[start] = 0
    queue = Queue()
    queue.put(start)
    while not queue.empty():
        v = queue.get()
        for u in graph[v]:
            if not visited[u]:
                visited[u] = True
                queue.put(u)
                dist[u] = dist[v] + 1
                pred[u] = v
                if u == end:
                    return True
    return False

def shortestpath(graph: [[int]], start: int, end: int) -> [int]:
    path = []
    pred = [-1 for _ in range(len(graph))]
    dist = [float('inf') for _ in range(len(graph))]
    if not bfs(graph, start, end, pred, dist):
        print(dist[end])
        return path
    path.append(end)
    v = end
    while pred[v] != -1:
        path.append(pred[v])
        v = pred[v]
    print(dist[end])
    return path