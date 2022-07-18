import collections


N, M = map(int, input().split())

graph = collections.defaultdict(set)

kb_nums = []

for _ in range(M):
    f1, f2 = map(int, input().split())
    graph[f1].add(f2)
    graph[f2].add(f1)

for person in range(1, N + 1):
    kb_num = 0
    count = 0
    queue = collections.deque()
    queue.append(person)
    visited = set()
    visited.add(person)
    while queue:
        count += 1
        for _ in range(len(queue)):
            v = queue.popleft()
            for friend in graph[v]:
                if friend not in visited:
                    queue.append(friend)
                    visited.add(friend)
                    kb_num += count
    kb_nums.append(kb_num)

print(kb_nums.index((min(kb_nums))) + 1)
