import collections

num_computers = int(input())
pairs = int(input())
graph = collections.defaultdict(list)
for _ in range(pairs):
    com1, com2 = map(int, input().split())
    graph[com1].append(com2)
    graph[com2].append(com1)


def DFS(v, infected=[]):
    infected.append(v)
    for w in graph[v]:
        if w not in infected:
            infected = DFS(w, infected)
    return infected


print(len(DFS(1)) - 1)
