import pprint

N = int(input())

graph = [[] for i in range(N)]

group_num = 0
home_nums = []

for _ in range(N):
    row = input()
    for char in row:
        graph[_].append(int(char))


def DFS(x, y, home_num=0):
    graph[y][x] = 0
    home_num += 1
    if x > 0:
        if graph[y][x - 1]:
            home_num = DFS(x - 1, y, home_num)
    if x < N - 1:
        if graph[y][x + 1]:
            home_num = DFS(x + 1, y, home_num)
    if y > 0:
        if graph[y - 1][x]:
            home_num = DFS(x, y - 1, home_num)
    if y < N - 1:
        if graph[y + 1][x]:
            home_num = DFS(x, y + 1, home_num)
    return home_num


for y in range(N):
    for x in range(N):
        if graph[y][x] == 1:
            home_nums.append(DFS(x, y))
            group_num += 1

print(group_num)
home_nums.sort()
print(*home_nums, sep="\n")
