from queue import LifoQueue

def dfs(graph: [[int]], v: int, id: int, stack: LifoQueue, onStack: [bool], ids: [int], low: [int]) -> None:
    stack.put(v)
    ids[v] = id
    low[v] = id
    id += 1
    for u in graph[v]:
        if ids[u] == -1:
            dfs(graph, u, id, stack, onStack, ids, low)
        if onStack[u]:
            low[v] = min(low[v], low[u])
    if low[v] == ids[v]:
        while not stack.empty():
            u = stack.get()
            onStack[u] = False
            low[u] = ids[v]
            if u == v:
                break

def tarjan(graph: [[int]]) -> [int]:
    id = 0
    stack = LifoQueue()
    onStack = [False for _ in range(len(graph))]
    ids = [-1 for _ in range(len(graph))]
    low = [0 for _ in range(len(graph))]
    for v in range(len(graph)):
        if ids[v] == -1:
            dfs(graph, v, id, stack, onStack, ids, low)
    return low