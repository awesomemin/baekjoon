import collections
N, M = map(int, input().split())

maze = []

for _ in range(N):
    row = [int(i) for i in input()]
    maze.append(row)


def BFS():
    count = 1
    visited = set()
    visited.add((0, 0))
    queue = collections.deque()
    queue.append((0, 0))
    while queue:
        for _ in range(len(queue)):
            v = queue.popleft()
            if v == (M - 1, N - 1):
                return count
            if v[0] - 1 >= 0 and (v[0] - 1, v[1]) not in visited and maze[v[1]][v[0] - 1] == 1:
                queue.append((v[0] - 1, v[1]))
                visited.add((v[0] - 1, v[1]))
            if v[0] + 1 < M and (v[0] + 1, v[1]) not in visited and maze[v[1]][v[0] + 1] == 1:
                queue.append((v[0] + 1, v[1]))
                visited.add((v[0] + 1, v[1]))
            if v[1] - 1 >= 0 and (v[0], v[1] - 1) not in visited and maze[v[1] - 1][v[0]] == 1:
                queue.append((v[0], v[1] - 1))
                visited.add((v[0], v[1] - 1))
            if v[1] + 1 < N and (v[0], v[1] + 1) not in visited and maze[v[1] + 1][v[0]] == 1:
                queue.append((v[0], v[1] + 1))
                visited.add((v[0], v[1] + 1))
        count += 1


print(BFS())
