from copy import deepcopy
import sys
sys.setrecursionlimit(10 ** 6)


N = int(input())

graph = []

for _ in range(N):
    row = [char for char in input()]
    graph.append(row)

graph_blind = deepcopy(graph)
for y, row in enumerate(graph_blind):
    for x, color in enumerate(row):
        if color == "G":
            graph_blind[y][x] = "R"


def DFS_Normal(x, y, color):
    if x < 0 or x >= N or y < 0 or y >= N:
        return
    if graph[y][x] == color:
        graph[y][x] = "0"
        DFS_Normal(x - 1, y, color)
        DFS_Normal(x + 1, y, color)
        DFS_Normal(x, y - 1, color)
        DFS_Normal(x, y + 1, color)


def DFS_Blind(x, y, color):
    if x < 0 or x >= N or y < 0 or y >= N:
        return
    if graph_blind[y][x] == color:
        graph_blind[y][x] = "0"
        DFS_Blind(x - 1, y, color)
        DFS_Blind(x + 1, y, color)
        DFS_Blind(x, y - 1, color)
        DFS_Blind(x, y + 1, color)


normal = 0
blind = 0
for y in range(N):
    for x in range(N):
        if graph[y][x] != "0":
            DFS_Normal(x, y, graph[y][x])
            normal += 1

for y in range(N):
    for x in range(N):
        if graph_blind[y][x] != "0":
            DFS_Blind(x, y, graph_blind[y][x])
            blind += 1

print(normal, blind)
