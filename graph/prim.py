from queue import PriorityQueue

def addedges(graph: [[int]], v: int, visited: [bool], pq: PriorityQueue) -> None:
    visited[v] = True
    for t in graph[v]:
        u, w = t[0], t[1]
        if not visited[u]:
            pq.put((w, (v, u)))

def prim(graph: [[int]], s: int) -> [int]:
    visited = [False for _ in range(len(graph))]
    pq = PriorityQueue()
    mst = []
    count, cost, m = 0, 0, len(graph)-1
    addedges(graph, s, visited, pq)
    while not pq.empty() and count != m:
        t = pq.get()
        w, v, u = t[0], t[1][0], t[1][1]
        if visited[u]:
            continue
        mst.append((v, u))
        count += 1
        cost += w
        addedges(graph, u, visited, pq)
    if count != m:
        print(float('inf'))
        return []
    print(cost)
    return mst

if __name__ == "__main__":
    V, E = [int(x) for x in input().split()]
    graph = [[] for _ in range(V)]
    for _ in range(E):
        u, v, w = [int(x) for x in input().split()]
        graph[u].append([v, w])
        graph[v].append([u, w])
    print(prim(graph, 0))