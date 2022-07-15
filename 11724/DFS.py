import collections
import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N, M = map(int, input().split())

graph = collections.defaultdict(list)

for _ in range(M):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

discovered = []


def DFS(n):
    if n in discovered:
        return 0
    discovered.append(n)
    for w in graph[n]:
        if w not in discovered:
            DFS(w)


CC = 0

for n in range(1, N + 1):
    if n not in discovered:
        DFS(n)
        CC += 1

print(CC)
