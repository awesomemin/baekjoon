import sys
sys.setrecursionlimit(10 ** 6)


def DFS(x, y):
    graph[y][x] = 0
    if x > 0:
        if graph[y][x - 1]:
            DFS(x - 1, y)
    if x < M - 1:
        if graph[y][x + 1]:
            DFS(x + 1, y)
    if y > 0:
        if graph[y - 1][x]:
            DFS(x, y - 1)
    if y < N - 1:
        if graph[y + 1][x]:
            DFS(x, y + 1)


T = int(input())
for _ in range(T):
    worm = 0
    M, N, K = map(int, input().split())
    graph = [[0] * M for i in range(N)]
    for __ in range(K):
        X, Y = map(int, input().split())
        graph[Y][X] = 1
    for i in range(0, M):
        for j in range(0, N):
            if graph[j][i] == 1:
                DFS(i, j)
                worm += 1
    print(worm)
