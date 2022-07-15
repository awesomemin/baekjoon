import collections
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = collections.defaultdict(list)
for _ in range(M):
    N1, N2 = map(int, input().split())
    graph[N1].append(N2)
    graph[N2].append(N1)

discovered = set()
CC = 0

for n in range(1, N + 1):
    queue = collections.deque()
    if n not in discovered:
        queue.append(n)
        while queue:
            v = queue.popleft()
            for w in graph[v]:
                if w not in discovered:
                    queue.append(w)
                    discovered.add(w)
        CC += 1

print(CC)
