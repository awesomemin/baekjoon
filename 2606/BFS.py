import collections

num_computers = int(input())
pairs = int(input())
graph = collections.defaultdict(list)
for _ in range(pairs):
    com1, com2 = map(int, input().split())
    graph[com1].append(com2)
    graph[com2].append(com1)


def BFS(start_v):
    infected = [start_v]
    queue = [start_v]
    while queue:
        v = queue.pop(0)
        for w in graph[v]:
            if w not in infected:
                infected.append(w)
                queue.append(w)
    return infected


print(len(BFS(1)) - 1)
