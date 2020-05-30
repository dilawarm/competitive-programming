def haseuler(inn: [int], out: [int], V: int) -> bool:
    start, end = 0, 0
    for i in range(V):
        if inn[i] - out[i] > 1 or out[i] - inn[i] > 1:
            return False
        elif inn[i] - out[i] == 1:
            end += 1
        elif out[i] - inn[i] == 1:
            start += 1
    return (start == 0 and end == 0) or (start == 1 and end == 1)

def start(inn: [int], out: [int], V: int) -> int:
    s = 0
    for i in range(V):
        if out[i] - inn[i] == 1:
            return i
        if out[i] > 0:
            return i
    return s
    
def dfs(graph: [[int]], v: int, out: [int], path: [int]) -> None:
    while out[v] != 0:
        out[v] -= 1
        u = graph[v][out[v]]
        dfs(graph, u, out, path)
    path.append(v)

def euler(graph: [[int]], V: int, E: int) -> [int]:
    path = []
    inn = [0 for _ in range(V)]
    out = [0 for _ in range(V)]
    for v in range(V):
        for u in graph[v]:
            out[v] += 1
            inn[u] += 1
    if not haseuler(inn, out, V):
        return path
    s = start(inn, out, V)
    dfs(graph, s, out, path)
    if len(path) == E+1:
        return path[::-1]
    return []