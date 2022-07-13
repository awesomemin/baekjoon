import collections
from dis import disco
N, M, V = map(int, input().split())

graph = collections.defaultdict(list)

for _ in range(M):
    N1, N2 = map(int, input().split())
    graph[N1].append(N2)
    graph[N2].append(N1)

for _ in graph.values():
    _.sort()


def DFS(v, discovered=[]):
    discovered.append(v)
    for w in graph[v]:
        if w not in discovered:
            discovered = DFS(w, discovered)
    return discovered


def BFS(start_v):
    discovered = [start_v]
    queue = [start_v]
    while queue:
        v = queue.pop(0)
        for w in graph[v]:
            if w not in discovered:
                discovered.append(w)
                queue.append(w)
    return discovered


print(*DFS(V))
print(*BFS(V))
